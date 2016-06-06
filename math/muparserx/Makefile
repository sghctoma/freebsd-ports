# $FreeBSD$

PORTNAME=	muparserx
PORTVERSION=	4.0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	sghctoma@gmail.com
COMMENT=	C++ Library for Parsing Expressions

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	beltoforion

USES=	compiler:c++11-lib cmake
CXXFLAGS+=	-stdlib=libc++ \
	-std=c++11 \
	-Wno-inconsistent-missing-override
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include <bsd.port.mk>
