#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function
import requests 
from bs4 import BeautifulSoup as ScrapySoup
import json
import sys


python_version = sys.version_info.major

if python_version == 2:
	from urlparse import urljoin
else:
	from urllib.parse import urljoin


URL_PRINCIPAL = "http://nuevodia.com.ve/"

URLS_MODULOS_NOTICIAS = []

PETICION = requests.get(URL_PRINCIPAL)

if PETICION.status_code == 200:
	
	scrapy_html = ScrapySoup(PETICION.text,'lxml')

	elementos = scrapy_html.find_all('li',{'class':'submenu'})

	modulos = elementos[1].ul.find_all('a')
	URLS_MODULOS_NOTICIAS =  map(lambda elem: elem.get('href'), modulos)

	for url_modulo in URLS_MODULOS_NOTICIAS:
		peticion_tmp = requests.get(urljoin(URL_PRINCIPAL,url_modulo))

		if peticion_tmp.status_code in [200]:
			#scrapy_html = ScrapySoup(PETICION.text,'lxml')			
			print(peticion_tmp.text)
		else:
			print("Error http %d"%peticion_tmp.status_code)
else:
	print("Error http %d"%PETICION.status_code)
