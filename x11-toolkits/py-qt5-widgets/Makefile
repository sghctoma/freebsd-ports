# $FreeBSD$

PORTNAME=	widgets
CATEGORIES=	x11-toolkits devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtGui module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	${PKGNAMEPREFIX}core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt5-core

CONFIGURE_ARGS=	--enable QtWidgets
PYQT5_DIST=	yes
USE_QT5=	gui widgets qmake_build buildtools_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtGui API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${QSCIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2.so:${PORTSDIR}/devel/qscintilla2
DEBUG_CONFIGURE_ON=	--debug --trace

BROKEN_sparc64=	Does not compile on sparc64

.include "${.CURDIR}/../../devel/py-qt5/bsd.pyqt.mk"
.include <bsd.port.mk>
