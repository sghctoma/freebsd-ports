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
- QtBluetooth (**not yet available**)
- QtDBus (**not yet available**)
- QtDesigner (**not yet available**)
- QtGui (x11-toolkits/py-qt5-gui)
- QtHelp (**not yet available**)
- QtLocation (**not yet available**)
- QtMultimedis (**not yet available**)
- QtMultimediaWidgets (**not yet available**)
- QtNetwork (**not yet available**)
- QtNfc (**not yet available**)
- QtOpenGL (**not yet available**)
- QtPositioning (**not yet available**)
- QtPrintSupport (**not yet available**)
- QtQml (**not yet available**)
- QtQuick (**not yet available**)
- QtQuickWidgets (**not yet available**)
- QtSensors (**not yet available**)
- QtSerialPort (**not yet available**)
- QtSql (**not yet available**)
- QtSvg (**not yet available**)
- QtTest (**not yet available**)
- QtWebChannel (**not yet available**)
- QtWebEngineWidgets (**not yet available**)
- QtWebKit (**not yet available**)
- QtWebKitWidgets (**not yet available**)
- QtWebSockets (**not yet available**)
- QtWidgets (**not yet available**)
- QtX11Extras (**not yet available**)
- QtXml (**not yet available**)
- QtXmlPattern (**not yet available**)
