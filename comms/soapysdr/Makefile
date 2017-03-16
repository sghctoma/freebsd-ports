# $FreeBSD$

PORTNAME=	soapysdr
PORTVERSION=	0.5.4
DISTVERSIONPREFIX=	soapy-sdr-
CATEGORIES=	comms

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Neutral and platform independent SDR support library

LICENSE=	BSL

USE_GITHUB=	yes
GH_ACCOUNT=	pothosware
GH_PROJECT=	SoapySDR

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/SoapySDR/modules0.5-2

USES=	cmake

.include <bsd.port.mk>
