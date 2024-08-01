/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -fprefix=cam_ -no-gen-BER -no-gen-XER -no-gen-JER -no-gen-OER -no-gen-example -gen-UPER`
 */

#ifndef	_cam_AccelerationControl_H_
#define	_cam_AccelerationControl_H_


#include <etsi_its_cam_coding/asn_application.h>

/* Including external dependencies */
#include <etsi_its_cam_coding/BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum cam_AccelerationControl {
	cam_AccelerationControl_brakePedalEngaged	= 0,
	cam_AccelerationControl_gasPedalEngaged	= 1,
	cam_AccelerationControl_emergencyBrakeEngaged	= 2,
	cam_AccelerationControl_collisionWarningEngaged	= 3,
	cam_AccelerationControl_accEngaged	= 4,
	cam_AccelerationControl_cruiseControlEngaged	= 5,
	cam_AccelerationControl_speedLimiterEngaged	= 6
} e_cam_AccelerationControl;

/* cam_AccelerationControl */
typedef BIT_STRING_t	 cam_AccelerationControl_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_cam_AccelerationControl_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_cam_AccelerationControl;
asn_struct_free_f cam_AccelerationControl_free;
asn_struct_print_f cam_AccelerationControl_print;
asn_constr_check_f cam_AccelerationControl_constraint;
per_type_decoder_f cam_AccelerationControl_decode_uper;
per_type_encoder_f cam_AccelerationControl_encode_uper;
per_type_decoder_f cam_AccelerationControl_decode_aper;
per_type_encoder_f cam_AccelerationControl_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _cam_AccelerationControl_H_ */
#include <etsi_its_cam_coding/asn_internal.h>
