# $FreeBSD$

PORTNAME=	soapyrtlsdr
PORTVERSION=	0.2.2
DISTVERSIONPREFIX=	soapy-rtlsdr-
CATEGORIES=	comms

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Plugin module to use the RTL-SDR dongle within the SoapySDR API

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	pothosware
GH_PROJECT=	SoapyRTLSDR

USES=	compiler:c++11-lib cmake
CXXFLAGS+=	-stdlib=libc++ \
	-std=c++11 \
	-Wno-c++11-extensions \
	-Wno-inconsistent-missing-override

PLIST_FILES=	lib/SoapySDR/modules0.5-2/librtlsdrSupport.so

.include <bsd.port.mk>
