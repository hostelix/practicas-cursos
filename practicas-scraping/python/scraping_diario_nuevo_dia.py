#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import requests 
from bs4 import BeautifulSoup as ScrapySoup
import json
import sys
import threading
import logging

python_version = sys.version_info.major

if python_version == 2:
	from urlparse import urljoin
else:
	from urllib.parse import urljoin

mutex = threading.Lock()

## Configuracion para el logging de los hilos ###
#logging.basicConfig(level=logging.DEBUG, format='[%(levelname)s] - %(threadName)-10s : %(message)s')

def procesar_modulo(_url_main, _url_modulo):
	
	peticion_tmp = requests.get(urljoin(_url_main,_url_modulo['url']))
	
	if peticion_tmp.status_code == 200:
		
		scrapy_html = ScrapySoup(peticion_tmp.text,'lxml')			
		
		contenedor_post = scrapy_html.find('ul',{'class':'blog big'})

		noticias = contenedor_post.find_all('li',{'class':'post'})

		noticias_JSON = []

		for noticia in noticias:
			imagen_noticia = noticia.find('img').get('src')
			contenido_noticia = noticia.find('div',{'class':'post_content'})
			link_noticia_obj = contenido_noticia.find('a')
			link = link_noticia_obj.get('href')
			titulo = link_noticia_obj.getText()
			fecha_noticia = contenido_noticia.find('li',{'class':'date'})

			noticias_JSON.append({
				'imagen': imagen_noticia,
				'link': urljoin(_url_main,link),
				'titulo': titulo,
				'fecha': fecha_noticia.getText().strip()
			})

		text_json = json.dumps(noticias_JSON, sort_keys=True,indent=4, separators=(',', ': '))
		
		
		name_file = url_modulo['titulo']+'.json'
		fichero = open(name_file, 'w')
		fichero.write(text_json)
		fichero.close()

	else:
		print("Error http %d"%peticion_tmp.status_code)

URL_PRINCIPAL = "http://nuevodia.com.ve/"

URLS_CATEGORIAS = []

PETICION = requests.get(URL_PRINCIPAL)

if PETICION.status_code == 200:
	
	scrapy_html = ScrapySoup(PETICION.text,'lxml')

	elementos = scrapy_html.find_all('li',{'class':'submenu'})

	modulos = elementos[1].ul.find_all('a')

	URLS_CATEGORIAS =  map(lambda elem: {
		'url': elem.get('href'), 
		'titulo': elem.get('title')
	}, modulos)

	hilos = list()
	
	for url_modulo in URLS_CATEGORIAS:
		hilo = threading.Thread(target=procesar_modulo, args=(URL_PRINCIPAL,url_modulo))
		hilos.append(hilo)
		hilo.start()
		hilo.join()

else:
	print("Error http %d"%PETICION.status_code)
