/*
 * Generated by asn1c-0.9.29-DF (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-UPER`
 */


/* Including external dependencies */
#include "etsi_its_cam_coding/StationID.h"
#include "etsi_its_cam_coding/SequenceNumber.h"
#include <etsi_its_cam_coding/constr_SEQUENCE.h>
#ifndef	_ActionID_H_
#define	_ActionID_H_


#include <etsi_its_cam_coding/asn_application.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ActionID */
typedef struct ActionID {
	StationID_t	 originatingStationID;
	SequenceNumber_t	 sequenceNumber;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ActionID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ActionID;

#ifdef __cplusplus
}
#endif

#endif	/* _ActionID_H_ */
#include <etsi_its_cam_coding/asn_internal.h>
