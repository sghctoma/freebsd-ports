# $FreeBSD$

PORTNAME=	qt5
PORTVERSION=	${PYQT5_VERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt 5 toolkit (meta port)

USES=		metaport python

OPTIONS_DEFINE=	ALL ${PYQT5_COMPONENTS}
OPTIONS_DEFAULT=	ALL
ALL_DESC=	All PyQt5 components

.include "${.CURDIR}/bsd.pyqt.mk"

.for component in ${PYQT5_COMPONENTS}
${component}_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt5-${component}>=0:${PORTSDIR}/${${component}_PORT}
ALL_RUN_DEPENDS+=		${${component}_RUN_DEPENDS}
.endfor

.include <bsd.port.mk>
