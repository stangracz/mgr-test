import os

# initial values
class initialValues:
	systems = ['posix']
	single = 'data/single/'
	paired = 'data/paired/'
	filename = 'list.tmp'
	

# exceptions
class Error(Exception):
	text = 'ERROR: Undefined execution error'
class badOSErr(Error):
	text = 'ERROR: Progam can be called only in Linux'
class badPathErr(Error):
	text = 'ERROR: These paths indicates any files:\n' + \
		'SINGLE: "' + initialValues.single + \
		'"\nPAIRED: "' + initialValues.paired + '"'

# program execution
class Filelist:
	def __init__(self):
		self.__checkOS()
		self.__checkPaths()
		self.__createFile()
		self.__populateFiles()
	def __checkOS(self):	
		osFlag = 0		
		for i in initialValues.systems:
			if (os.name == i):
				osFlag = 1
		if (osFlag != 1):
			raise badOSErr
	def __checkPaths(self):
		try:
			self.__single = os.listdir(initialValues.single)
			paired_cat = os.listdir(initialValues.paired)
			tab = []
			for i in paired_cat:
				if (i != initialValues.filename):
					files = os.listdir(initialValues.paired + '/' + i)
					for j in files:
						j = i + '/' + j				
						tab.append([j])
					tab.append(',')		
			self.__paired = tab
		except:
			raise #badPathErr
	def __createFile(self):
		self.__fSingle = open(initialValues.single + initialValues.filename,'w')
		self.__fPaired = open(initialValues.paired + initialValues.filename,'w')
	def __populateFiles(self):
		for i in self.__single:
			if (i != initialValues.filename):
				self.__fSingle.write(i + ';')
		for i in self.__paired:
			for j in i:
				self.__fPaired.write(j + ';')
		
try:
	Filelist()
except badOSErr as e:
	print(e.text)	
except badPathErr as e:
	print(e.text)
