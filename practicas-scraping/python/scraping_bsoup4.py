#!/usr/bin/env python
# -*- coding: utf-8 -*-

import requests 
from bs4 import BeautifulSoup as ScrapySoup
import json

URL = "https://news.ycombinator.com/"

PETICION = requests.get(URL)

name_file = 'news.ycombinator.com.json'

if PETICION.status_code == 200:
	
	scrapy_html = ScrapySoup(PETICION.text,'lxml')

	elementos = scrapy_html.find_all('tr',{'class':'athing'})

	elementos_JSON = []

	for elemento in elementos:
		#Atributos del objeto
		rank = elemento.find('span',{'class':'rank'}).getText()
		post = elemento.find_all('td',{'class':'title'})[1]
		link = post.a.get('href')
		title = post.a.getText()

		elementos_JSON.append({
			'rank': rank[:len(rank)-1],
			'link': link,
			'title': title
		});
	
	text_json = json.dumps(elementos_JSON, sort_keys=True,indent=4, separators=(',', ': '))
	
	fichero = open(name_file, 'w')
	fichero.write(text_json)
	fichero.close()

	print "Scraping finish"

else:
	print "Error http %d"%PETICION.status_code
