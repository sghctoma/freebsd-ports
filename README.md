sghctoma's FreeBSD ports playground
===================================

Some ports for FreeBSD that are mostly usable for my use cases but not quite
ready to PR them.

astro/garmintools
-----------------

This port rovides users with the ability to communicate with various Garmin
sport watches and bike computers.

WWW: http://garmintools.googlecode.com

astro/garminplugin
------------------

This browser plugin has the same methods and properties as the official
Garmin Communicator Plugin (http://www8.garmin.com/products/communicator/).
It can be used to transfer GPX files (Geocache Descriptions) to your garmin
device using the official Garmin Javascript API. Its functionality depends on
the device you use.
- Edge305/Forerunner305: ReadFitnessData, ReadGpsData, No write support
- Edge705/Oregon/Dakota: ReadFitnessData, ReadGpsData, Write Gpx files
- Edge800: ReadFitnessData, Write Gpx/Tcx Files
- Other devices: Executes external command to write Gpx to device

WWW: http://www.andreas-diesner.de/garminplugin

devel/py-qt5
-----------

PyQt5 is a set of Python bindings for v5 of the Qt application framework from
the Qt Company.
This package provides the PyQt5 metaport.

WWW: http://www.riverbankcomputing.co.uk/software/pyqt/

This metaport consists of the following ports:

- QtCore (devel/py-qt5-core)
- QtBluetooth (*not yet available*) 
- QtDBus (*not yet available*)
- QtDesigne (*not yet available*)r
- QtGu (*not yet available*)i
- QtHel (*not yet available*)p
- QtLocatio (*not yet available*)n
- QtMultimedi (*not yet available*)a
- QtMultimediaWidget (*not yet available*)s
- QtNetwor (*not yet available*)k
- QtNf (*not yet available*)c
- QtOpenG (*not yet available*)L
- QtPositionin (*not yet available*)g
- QtPrintSuppor (*not yet available*)t
- QtQm (*not yet available*)l
- QtQuic (*not yet available*)k
- QtQuickWidget (*not yet available*)s
- QtSensor (*not yet available*)s
- QtSerialPort (*not yet available*) 
- QtSq (*not yet available*)l
- QtSv (*not yet available*)g
- QtTest (*not yet available*) 
- QtWebChanne (*not yet available*)l
- QtWebEngineWidget (*not yet available*)s
- QtWebKit (*not yet available*) 
- QtWebKitWidgets (*not yet available*) 
- QtWebSockets (*not yet available*) 
- QtWidgets (*not yet available*) 
- QtX11Extra (*not yet available*)s
- QtXml (*not yet available*) 
- QtXmlPattern (*not yet available*
