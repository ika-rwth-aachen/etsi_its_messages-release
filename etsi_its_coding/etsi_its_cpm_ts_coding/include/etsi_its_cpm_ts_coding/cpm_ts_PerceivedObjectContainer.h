/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CPM-PerceivedObjectContainer"
 * 	found in "/input/CPM-PerceivedObjectContainer.asn"
 * 	`asn1c -fcompound-names -fprefix=cpm_ts_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_cpm_ts_PerceivedObjectContainer_H_
#define	_cpm_ts_PerceivedObjectContainer_H_


#include <etsi_its_cpm_ts_coding/asn_application.h>

/* Including external dependencies */
#include "etsi_its_cpm_ts_coding/cpm_ts_CardinalNumber1B.h"
#include "etsi_its_cpm_ts_coding/cpm_ts_PerceivedObjects.h"
#include <etsi_its_cpm_ts_coding/constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* cpm_ts_PerceivedObjectContainer */
typedef struct cpm_ts_PerceivedObjectContainer {
	cpm_ts_CardinalNumber1B_t	 numberOfPerceivedObjects;
	cpm_ts_PerceivedObjects_t	 perceivedObjects;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} cpm_ts_PerceivedObjectContainer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_cpm_ts_PerceivedObjectContainer;
extern asn_SEQUENCE_specifics_t asn_SPC_cpm_ts_PerceivedObjectContainer_specs_1;
extern asn_TYPE_member_t asn_MBR_cpm_ts_PerceivedObjectContainer_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _cpm_ts_PerceivedObjectContainer_H_ */
#include <etsi_its_cpm_ts_coding/asn_internal.h>