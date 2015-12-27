#! /usr/bin/python
import sys
from interfaz import *


class Ventana(QtGui.QDialog):
	def __init__(self, parent = None):
		QtGui.QWidget.__init__(self,parent)
		self.ui = Ui_Dialog()
		self.ui.setupUi(self)

		QtCore.QObject.connect(self.ui.pushButton, QtCore.SIGNAL("clicked()"),self.mostrar)

	def mostrar(self):
		self.ui.lineEdit.setText("Hola, como estas %s ?"%(self.ui.lineEdit.text()))

if __name__ == '__main__':
	app = QtGui.QApplication(sys.argv)
	main = Ventana()

	main.show()

	sys.exit(app.exec_())
