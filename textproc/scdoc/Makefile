# $FreeBSD$

PORTNAME=	scdoc
PORTVERSION=	1.5.2
CATEGORIES=	textproc
MASTER_SITES=	https://git.sr.ht/~sircmpwn/scdoc/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	sghctoma@gmail.com
COMMENT=	Simple man page generator written for POSIX systems written in C99

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/COPYING

USE_HARDENING=	pie:off

USES=	gmake

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV=	MANDIR=${STAGEDIR}/${PREFIX}/man/

PLIST_FILES=	bin/scdoc \
				man/man1/scdoc.1.gz

.include <bsd.port.mk>
