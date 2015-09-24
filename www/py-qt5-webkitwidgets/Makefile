# $FreeBSD$

PORTNAME=	webkitwidgets
CATEGORIES=	www devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtWebKit module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PKGNAMEPREFIX}gui>=${PYQT5_VERSION}:${PORTSDIR}/x11-toolkits/py-qt5-gui

CONFIGURE_ARGS=	--enable QtWebKitWidgets
PYQT5_DIST=	yes
USE_QT5=	qmake_build gui buildtools_build network webkit

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtWebKit API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${QSCIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2.so:${PORTSDIR}/devel/qscintilla2
DEBUG_CONFIGURE_ON=	--debug --trace

.include "${.CURDIR}/../../devel/py-qt5/bsd.pyqt.mk"
.include <bsd.port.mk>
