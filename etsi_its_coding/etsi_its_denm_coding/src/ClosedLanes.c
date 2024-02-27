/*
 * Generated by asn1c-0.9.29-DF (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "/input/ITS-Container.asn"
 * 	`asn1c -fcompound-names -no-gen-example -gen-UPER`
 */

#include "etsi_its_denm_coding/ClosedLanes.h"

asn_TYPE_member_t asn_MBR_ClosedLanes_1[] = {
	{ ATF_POINTER, 3, offsetof(struct ClosedLanes, innerhardShoulderStatus),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_HardShoulderStatus,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"innerhardShoulderStatus"
		},
	{ ATF_POINTER, 2, offsetof(struct ClosedLanes, outerhardShoulderStatus),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_HardShoulderStatus,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"outerhardShoulderStatus"
		},
	{ ATF_POINTER, 1, offsetof(struct ClosedLanes, drivingLaneStatus),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DrivingLaneStatus,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"drivingLaneStatus"
		},
};
static const int asn_MAP_ClosedLanes_oms_1[] = { 0, 1, 2 };
static const ber_tlv_tag_t asn_DEF_ClosedLanes_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ClosedLanes_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* innerhardShoulderStatus */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* outerhardShoulderStatus */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* drivingLaneStatus */
};
asn_SEQUENCE_specifics_t asn_SPC_ClosedLanes_specs_1 = {
	sizeof(struct ClosedLanes),
	offsetof(struct ClosedLanes, _asn_ctx),
	asn_MAP_ClosedLanes_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_ClosedLanes_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ClosedLanes = {
	"ClosedLanes",
	"ClosedLanes",
	&asn_OP_SEQUENCE,
	asn_DEF_ClosedLanes_tags_1,
	sizeof(asn_DEF_ClosedLanes_tags_1)
		/sizeof(asn_DEF_ClosedLanes_tags_1[0]), /* 1 */
	asn_DEF_ClosedLanes_tags_1,	/* Same as above */
	sizeof(asn_DEF_ClosedLanes_tags_1)
		/sizeof(asn_DEF_ClosedLanes_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_ClosedLanes_1,
	3,	/* Elements count */
	&asn_SPC_ClosedLanes_specs_1	/* Additional specs */
};

