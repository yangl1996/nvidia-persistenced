/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "nvpd_rpc.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <syslog.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

#include "nvidia-persistenced.h"

void
nvpd_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		SetPersistenceModeArgs nvpdsetpersistencemode_1_arg;
		GetPersistenceModeArgs nvpdgetpersistencemode_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case nvPdSetPersistenceMode:
		_xdr_argument = (xdrproc_t) xdr_SetPersistenceModeArgs;
		_xdr_result = (xdrproc_t) xdr_NvPdStatus;
		local = (char *(*)(char *, struct svc_req *)) nvpdsetpersistencemode_1_svc;
		break;

	case nvPdGetPersistenceMode:
		_xdr_argument = (xdrproc_t) xdr_GetPersistenceModeArgs;
		_xdr_result = (xdrproc_t) xdr_GetPersistenceModeRes;
		local = (char *(*)(char *, struct svc_req *)) nvpdgetpersistencemode_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		syslog (LOG_ERR, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}
