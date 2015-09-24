# Replacement for the composite module PyQ5.Qt for FreeBSD
# Provides namespace for all installed PyQt5 modules by importing them

from PyQt5.QtCore import *

try:
	from PyQt5.QtBluetooth import *
except ImportError:
	pass
try:
	from PyQt5.QtDBus import *
except ImportError:
	pass
try:
	from PyQt5.QtDesigner import *
except ImportError:
	pass
try:
	from PyQt5.QtGui import *
except ImportError:
	pass
try:
	from PyQt5.QtHelp import *
except ImportError:
	pass
try:
	from PyQt5.QtLocation import *
except ImportError:
	pass
try:
	from PyQt5.QtMultimedia import *
except ImportError:
	pass
try:
	from PyQt5.QtMultimediaWidgets import *
except ImportError:
	pass
try:
	from PyQt5.QtNetwork import *
except ImportError:
	pass
try:
	from PyQt5.QtNfc import *
except ImportError:
	pass
try:
	from PyQt5.QtOpenGL import *
except ImportError:
	pass
try:
	from PyQt5.QtPositioning import *
except ImportError:
	pass
try:
	from PyQt5.QtPrintSupport import *
except ImportError:
	pass
try:
	from PyQt5.QtQml import *
except ImportError:
	pass
try:
	from PyQt5.QtQuick import *
except ImportError:
	pass
try:
	from PyQt5.QtQuickWidgets import *
except ImportError:
	pass
try:
	from PyQt5.QtSensors import *
except ImportError:
	pass
try:
	from PyQt5.QtSerialPort import *
except ImportError:
	pass
try:
	from PyQt5.QtSql import *
except ImportError:
	pass
try:
	from PyQt5.QtSvg import *
except ImportError:
	pass
try:
	from PyQt5.QtTest import *
except ImportError:
	pass
try:
	from PyQt5.QtWebChannel import *
except ImportError:
	pass
try:
	from PyQt5.QtWebEngineWidgets import *
except ImportError:
	pass
try:
	from PyQt5.QtWebKit import *
except ImportError:
	pass
try:
	from PyQt5.QtWebKitWidgets import *
except ImportError:
	pass
try:
	from PyQt5.QtWebSockets import *
except ImportError:
	pass
try:
	from PyQt5.QtWidgets import *
except ImportError:
	pass
try:
	from PyQt5.QtX11Extras import *
except ImportError:
	pass
try:
	from PyQt5.QtXml import *
except ImportError:
	pass
try:
	from PyQt5.QtXmlPatterns import *
except ImportError:
	pass

