# $FreeBSD$

PORTNAME=	limesuite
PORTVERSION=	17.02.1
DISTVERSIONPREFIX=	v
CATEGORIES=	comms

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Driver and GUI for LMS7002M-based SDR platforms

LICENSE=	APACHE20

LIB_DEPENDS=	libSoapySDR.so:comms/soapysdr

USE_GITHUB=	yes
GH_ACCOUNT=	myriadrf
GH_PROJECT=	LimeSuite

USE_WX=	3.0
USE_GL=	glut glew

USES=	compiler:c++11-lib cmake sqlite:3
SUB_FILES=	lime.conf
CXXFLAGS+=	-stdlib=libc++ \
	-std=c++11 \
	-Wno-c++11-extensions \
	-Wno-inconsistent-missing-override \

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} "${WRKDIR}/lime.conf" ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
