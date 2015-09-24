# bsd.pyqt.mk - Global definitions for PyQt related ports
#
# $FreeBSD$
#
# Port variables:
# PYQT5_DIST            - This port is part of PyQt5 itself. Variables and
#                         targets are then set assuming a certain tarball and
#                         port layout.
#

PYQT_MAINTAINER=	kde@FreeBSD.org

MASTER_SITE_RIVERBANK=	http://www.riverbankcomputing.com/static/Downloads/%SUBDIR%/

MASTER_SITES_SIP=	SF/pyqt/sip/sip-${PORTVERSION} \
			${MASTER_SITE_GENTOO:S,%SUBDIR%,distfiles,}
MASTER_SITES_PYQT5=	SF/pyqt/PyQt5/PyQt-${PORTVERSION} \
			${MASTER_SITE_GENTOO:S,%SUBDIR%,distfiles,}
MASTER_SITES_QSCI2=	SF/pyqt/QScintilla2/QScintilla-${PORTVERSION} \
			${MASTER_SITE_GENTOO:S,%SUBDIR%,distfiles,}

SIP_VERSION=		4.16.5
PYQT5_VERSION=		5.4
QSCI2_VERSION=		2.8.4

SIP_DISTNAME=		sip-${SIP_VERSION}
PYQT5_DISTNAME=		PyQt-gpl-${PYQT5_VERSION}
PYQT5_DISTINFO_FILE=	${.CURDIR}/../../devel/py-qt5/distinfo
QSCI2_DISTNAME=		QScintilla-gpl-${QSCI2_VERSION}
QSCI2_DISTINFO_FILE=	${.CURDIR}/../../devel/qscintilla2/distinfo

PYQT5_COMPONENTS=	core bluetooth dbus dbussupport demo designer doc gui \
			help location multimedia multimediawidgets network nfc \
			opengl positioning printsupport qml qscintilla2 quick \
			quickwidgets sensors serialport sql svg test webchannel \
			webenginewidgets webkit webkitwidgets websockets \
			widgets x11extras xml xmlpatterns

core_PORT=		devel/py-qt5-core
bluetooth_PORT=		devel/py-qt5-bluetooth
dbus_PORT=		devel/py-qt5-dbus
dbussupport_PORT=	devel/py-qt5-dbussupport
demo_PORT=		misc/py-qt5-demo
designer_PORT=		devel/py-qt5-designer
doc_PORT=		misc/py-qt5-doc
gui_PORT=		x11-toolkits/py-qt5-gui
help_PORT=		devel/py-qt5-help
location_PORT=		devel/py-qt5-location
multimedia_PORT=	multimedia/py-qt5-multimedia
multimediawidgets_PORT=	multimedia/py-qt5-multimediawidgets
network_PORT=		net/py-qt5-network
nfc_PORT=		net/py-qt5-nfc
opengl_PORT=		x11/py-qt5-opengl
positioning_PORT=	devel/py-qt5-positioning
printsupport_PORT=	print/py-qt5-printsupport
qml_PORT=		x11-toolkits/py-qt5-qml
qscintilla2_PORT=       devel/py-qt4-qscintilla2
quick_PORT=		x11-toolkits/py-qt5-quick
quickwidgets_PORT=	x11-toolkits/py-qt5-quickwidgets
sensors_PORT=		devel/py-qt5-sensors
serialport_PORT=	devel/py-qt5-serialport
sql_PORT=		databases/py-qt5-sql
svg_PORT=		graphics/py-qt5-svg
test_PORT=		devel/py-qt5-test
webchannel_PORT=	www/py-qt5-webchannel
webenginewidgets_PORT=	www/py-qt5-webenginewidgets
webkit_PORT=		www/py-qt5-webkit
webkitwidgets_PORT=	www/py-qt5-webkitwidgets
websockets_PORT=	www/py-qt5-websockets
widgets_PORT=		x11-toolkits/py-qt5-widgets
x11extras_PORT=		x11-toolkits/py-qt5-x11extras
xml_PORT=		textproc/py-qt5-xml
xmlpatterns_PORT=	textproc/py-qt5-xmlpatterns

core_DESC=		Python bindings for QtCore module
bluetooth_DESC=		Python bindings for QtBluetooth module
dbus_DESC	=	Python bindings for QtDBus module
dbussupport_DESC=	Python bindings for D-Bus
demo_DESC=		PyQt5 demo and examples
designer_DESC=		Python bindings for QtDesigner module
designerplugin_DESC=	Python bindings for QtDesigner plugin
doc_DESC=		PyQt5 documentation
gui_DESC=		Python bindings for QtGui module
help_DESC=		Python bindings for QtHelp module
location_DESC=		Python bindings for QtLocation module
multimedia_DESC=	Python bindings for QtMultimedia module
multimediawidgets_DESC=	Python bindings for QtMultimediaWidgets module
network_DESC=		Python bindings for QtNetwork module
nfc_DESC=		Python bindings for QtNfc module
opengl_DESC=		Python bindings for QtOpenGL module
positioning_DESC=	Python bindings for QtPositioning module
printsupport_DESC=	Python bindings for QtPrintSupport module
qml_DESC=		Python bindings for QtQml module
qscintilla2_DESC=       Python bindings for QScintilla2
quick_DESC=		Python bindings for QtQuick module
quickwidgets_DESC=	Python bindings for QtQuickWidgets module
sensors_DESC=		Python bindings for QtSensors module
serialport_DESC=	Python bindings for QtSerialPort module
sql_DESC=		Python bindings for QtSql module
svg_DESC=		Python bindings for QtSvg module
test_DESC=		Python bindings for QtTest module
webchannel_DESC=	Python bindings for QtWebChannel module
webenginewidgets_DESC=	Python bindings for QtWebEngineWidgets module
webkit_DESC=		Python bindings for QtWebKit module
webkitwidgets_DESC=	Python bindings for QtWebKitWidgets module
websockets_DESC=	Python bindings for QtWebSockets module
widgets_DESC=		Python bindings for QtWidgets module
x11extras_DESC=		Python bindings for QtX11Extras module
xml_DESC=		Python bindings for QtXml module
xmlpatterns_DESC=	Python bindings for QtXmlPatterns module

# Stage support.
DESTDIRNAME=		INSTALL_ROOT

.if defined(PYQT5_DIST)
PORTVERSION=	${PYQT5_VERSION}
MASTER_SITES=	${MASTER_SITES_PYQT5}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt5-
DISTNAME=	${PYQT5_DISTNAME}

DISTINFO_FILE=	${PYQT5_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USES+=		python

QT_NONSTANDARD=	yes  # Do not add unknown arguments to CONFIGURE_ARGS.

PATCHDIR=	${.CURDIR}/../../devel/py-qt5-core/files
OPTIONSFILE?=	${PORT_DBDIR}/py-qt5-${PORTNAME}/options
SIPDIR=		${PREFIX}/share/py-sip
QSCIDIR=	${PREFIX}/share/qt5/qsci
CONFIGURE_ARGS+=-b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-q ${QMAKE} \
		--confirm-license \
		--sipdir ${SIPDIR}

# One of the things PyQt5 looks for to determine whether to build the Qt DBus
# main loop module (py-qt5-dbussupport) is whether the dbus/ directory is
# present. Only extract it for that port then.
.if ${PORTNAME} != "dbussupport"
EXTRACT_AFTER_ARGS+=	--exclude "${DISTNAME}/dbus"
.endif  # ${PORTNAME} != "dbussupport"

.if !target(do-configure)
do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}
.endif  # !target(do-configure)
.endif  # defined(PYQT5_DIST)

