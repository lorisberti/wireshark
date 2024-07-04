/* Do not modify this file. Changes will be overwritten.                      */
/* Generated automatically by the ASN.1 to Wireshark dissector compiler       */
/* packet-pkcs1.c                                                             */
/* asn2wrs.py -b -q -L -p pkcs1 -c ./pkcs1.cnf -s ./packet-pkcs1-template -D . -O ../.. PKIXAlgs-2009.asn */

/* packet-pkcs1.c
 * Routines for PKCS#1/RFC2313 packet dissection
 *  Ronnie Sahlberg 2004
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "config.h"

#include <epan/packet.h>
#include <epan/oids.h>
#include <epan/asn1.h>

#include "packet-ber.h"
#include "packet-pkcs1.h"
#include "packet-x509af.h"

#define PNAME  "PKCS#1"
#define PSNAME "PKCS-1"
#define PFNAME "pkcs-1"

void proto_register_pkcs1(void);
void proto_reg_handoff_pkcs1(void);

/* Initialize the protocol and registered fields */
static int proto_pkcs1;
static int hf_pkcs1_DSA_Params_PDU;               /* DSA_Params */
static int hf_pkcs1_DomainParameters_PDU;         /* DomainParameters */
static int hf_pkcs1_KEA_Params_Id_PDU;            /* KEA_Params_Id */
static int hf_pkcs1_HashAlgorithm_PDU;            /* HashAlgorithm */
static int hf_pkcs1_RSASSA_PSS_params_PDU;        /* RSASSA_PSS_params */
static int hf_pkcs1_ECParameters_PDU;             /* ECParameters */
static int hf_pkcs1_Prime_p_PDU;                  /* Prime_p */
static int hf_pkcs1_modulus;                      /* INTEGER */
static int hf_pkcs1_publicExponent;               /* INTEGER */
static int hf_pkcs1_digestAlgorithm;              /* DigestAlgorithmIdentifier */
static int hf_pkcs1_digest;                       /* Digest */
static int hf_pkcs1_p;                            /* INTEGER */
static int hf_pkcs1_q;                            /* INTEGER */
static int hf_pkcs1_g;                            /* INTEGER */
static int hf_pkcs1_j;                            /* INTEGER */
static int hf_pkcs1_validationParams;             /* ValidationParams */
static int hf_pkcs1_seed;                         /* BIT_STRING */
static int hf_pkcs1_pgenCounter;                  /* INTEGER */
static int hf_pkcs1_hashAlgorithm;                /* HashAlgorithm */
static int hf_pkcs1_maskGenAlgorithm;             /* MaskGenAlgorithm */
static int hf_pkcs1_saltLength;                   /* INTEGER */
static int hf_pkcs1_trailerField;                 /* INTEGER */
static int hf_pkcs1_specifiedCurve;               /* SpecifiedECDomain */
static int hf_pkcs1_namedCurve;                   /* OBJECT_IDENTIFIER */
static int hf_pkcs1_version;                      /* ECPVer */
static int hf_pkcs1_fieldID;                      /* FieldID */
static int hf_pkcs1_curve;                        /* Curve */
static int hf_pkcs1_base;                         /* ECPoint */
static int hf_pkcs1_order;                        /* INTEGER */
static int hf_pkcs1_cofactor;                     /* INTEGER */
static int hf_pkcs1_fieldType;                    /* T_fieldType */
static int hf_pkcs1_parameters;                   /* T_parameters */
static int hf_pkcs1_a;                            /* FieldElement */
static int hf_pkcs1_b;                            /* FieldElement */
static int hf_pkcs1_r;                            /* INTEGER */
static int hf_pkcs1_s;                            /* INTEGER */

/* Initialize the subtree pointers */
static int ett_pkcs1_RSAPublicKey;
static int ett_pkcs1_DigestInfo;
static int ett_pkcs1_DSA_Params;
static int ett_pkcs1_DomainParameters;
static int ett_pkcs1_ValidationParams;
static int ett_pkcs1_RSASSA_PSS_params;
static int ett_pkcs1_ECParameters;
static int ett_pkcs1_SpecifiedECDomain;
static int ett_pkcs1_FieldID;
static int ett_pkcs1_Curve;
static int ett_pkcs1_DSA_Sig_Value;
static int ett_pkcs1_ECDSA_Sig_Value;



static int
dissect_pkcs1_INTEGER(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}


static const ber_sequence_t RSAPublicKey_sequence[] = {
  { &hf_pkcs1_modulus       , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_publicExponent, BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { NULL, 0, 0, 0, NULL }
};

int
dissect_pkcs1_RSAPublicKey(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   RSAPublicKey_sequence, hf_index, ett_pkcs1_RSAPublicKey);

  return offset;
}



static int
dissect_pkcs1_DigestAlgorithmIdentifier(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_pkcs1_Digest(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t DigestInfo_sequence[] = {
  { &hf_pkcs1_digestAlgorithm, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_pkcs1_DigestAlgorithmIdentifier },
  { &hf_pkcs1_digest        , BER_CLASS_UNI, BER_UNI_TAG_OCTETSTRING, BER_FLAGS_NOOWNTAG, dissect_pkcs1_Digest },
  { NULL, 0, 0, 0, NULL }
};

int
dissect_pkcs1_DigestInfo(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   DigestInfo_sequence, hf_index, ett_pkcs1_DigestInfo);

  return offset;
}


static const ber_sequence_t DSA_Params_sequence[] = {
  { &hf_pkcs1_p             , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_q             , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_g             , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_pkcs1_DSA_Params(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   DSA_Params_sequence, hf_index, ett_pkcs1_DSA_Params);

  return offset;
}




static int
dissect_pkcs1_BIT_STRING(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
                                    NULL, 0, hf_index, -1,
                                    NULL);

  return offset;
}


static const ber_sequence_t ValidationParams_sequence[] = {
  { &hf_pkcs1_seed          , BER_CLASS_UNI, BER_UNI_TAG_BITSTRING, BER_FLAGS_NOOWNTAG, dissect_pkcs1_BIT_STRING },
  { &hf_pkcs1_pgenCounter   , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_pkcs1_ValidationParams(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ValidationParams_sequence, hf_index, ett_pkcs1_ValidationParams);

  return offset;
}


static const ber_sequence_t DomainParameters_sequence[] = {
  { &hf_pkcs1_p             , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_g             , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_q             , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_j             , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_validationParams, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_pkcs1_ValidationParams },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_pkcs1_DomainParameters(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   DomainParameters_sequence, hf_index, ett_pkcs1_DomainParameters);

  return offset;
}




static int
dissect_pkcs1_KEA_Params_Id(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_pkcs1_HashAlgorithm(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}



static int
dissect_pkcs1_MaskGenAlgorithm(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_x509af_AlgorithmIdentifier(implicit_tag, tvb, offset, actx, tree, hf_index);

  return offset;
}


static const ber_sequence_t RSASSA_PSS_params_sequence[] = {
  { &hf_pkcs1_hashAlgorithm , BER_CLASS_CON, 0, BER_FLAGS_OPTIONAL, dissect_pkcs1_HashAlgorithm },
  { &hf_pkcs1_maskGenAlgorithm, BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL, dissect_pkcs1_MaskGenAlgorithm },
  { &hf_pkcs1_saltLength    , BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_trailerField  , BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL, dissect_pkcs1_INTEGER },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_pkcs1_RSASSA_PSS_params(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   RSASSA_PSS_params_sequence, hf_index, ett_pkcs1_RSASSA_PSS_params);

  return offset;
}



static int
dissect_pkcs1_ECPoint(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const value_string pkcs1_ECPVer_vals[] = {
  {   1, "ecpVer1" },
  { 0, NULL }
};


static int
dissect_pkcs1_ECPVer(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}



static int
dissect_pkcs1_T_fieldType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_index, &actx->external.direct_reference);

  return offset;
}



static int
dissect_pkcs1_T_parameters(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);


  return offset;
}


static const ber_sequence_t FieldID_sequence[] = {
  { &hf_pkcs1_fieldType     , BER_CLASS_UNI, BER_UNI_TAG_OID, BER_FLAGS_NOOWNTAG, dissect_pkcs1_T_fieldType },
  { &hf_pkcs1_parameters    , BER_CLASS_ANY, 0, BER_FLAGS_NOOWNTAG, dissect_pkcs1_T_parameters },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_pkcs1_FieldID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   FieldID_sequence, hf_index, ett_pkcs1_FieldID);

  return offset;
}



static int
dissect_pkcs1_FieldElement(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t Curve_sequence[] = {
  { &hf_pkcs1_a             , BER_CLASS_UNI, BER_UNI_TAG_OCTETSTRING, BER_FLAGS_NOOWNTAG, dissect_pkcs1_FieldElement },
  { &hf_pkcs1_b             , BER_CLASS_UNI, BER_UNI_TAG_OCTETSTRING, BER_FLAGS_NOOWNTAG, dissect_pkcs1_FieldElement },
  { &hf_pkcs1_seed          , BER_CLASS_UNI, BER_UNI_TAG_BITSTRING, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_pkcs1_BIT_STRING },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_pkcs1_Curve(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   Curve_sequence, hf_index, ett_pkcs1_Curve);

  return offset;
}


static const ber_sequence_t SpecifiedECDomain_sequence[] = {
  { &hf_pkcs1_version       , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_ECPVer },
  { &hf_pkcs1_fieldID       , BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_pkcs1_FieldID },
  { &hf_pkcs1_curve         , BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_pkcs1_Curve },
  { &hf_pkcs1_base          , BER_CLASS_UNI, BER_UNI_TAG_OCTETSTRING, BER_FLAGS_NOOWNTAG, dissect_pkcs1_ECPoint },
  { &hf_pkcs1_order         , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { &hf_pkcs1_cofactor      , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_pkcs1_INTEGER },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_pkcs1_SpecifiedECDomain(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   SpecifiedECDomain_sequence, hf_index, ett_pkcs1_SpecifiedECDomain);

  return offset;
}



static int
dissect_pkcs1_OBJECT_IDENTIFIER(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);

  return offset;
}


static const value_string pkcs1_ECParameters_vals[] = {
  {   0, "specifiedCurve" },
  {   1, "namedCurve" },
  { 0, NULL }
};

static const ber_choice_t ECParameters_choice[] = {
  {   0, &hf_pkcs1_specifiedCurve, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_pkcs1_SpecifiedECDomain },
  {   1, &hf_pkcs1_namedCurve    , BER_CLASS_UNI, BER_UNI_TAG_OID, BER_FLAGS_NOOWNTAG, dissect_pkcs1_OBJECT_IDENTIFIER },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_pkcs1_ECParameters(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 ECParameters_choice, hf_index, ett_pkcs1_ECParameters,
                                 NULL);

  return offset;
}



static int
dissect_pkcs1_Prime_p(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}



/*--- PDUs ---*/

static int dissect_DSA_Params_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, true, pinfo);
  offset = dissect_pkcs1_DSA_Params(false, tvb, offset, &asn1_ctx, tree, hf_pkcs1_DSA_Params_PDU);
  return offset;
}
static int dissect_DomainParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, true, pinfo);
  offset = dissect_pkcs1_DomainParameters(false, tvb, offset, &asn1_ctx, tree, hf_pkcs1_DomainParameters_PDU);
  return offset;
}
static int dissect_KEA_Params_Id_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, true, pinfo);
  offset = dissect_pkcs1_KEA_Params_Id(false, tvb, offset, &asn1_ctx, tree, hf_pkcs1_KEA_Params_Id_PDU);
  return offset;
}
static int dissect_HashAlgorithm_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, true, pinfo);
  offset = dissect_pkcs1_HashAlgorithm(false, tvb, offset, &asn1_ctx, tree, hf_pkcs1_HashAlgorithm_PDU);
  return offset;
}
static int dissect_RSASSA_PSS_params_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, true, pinfo);
  offset = dissect_pkcs1_RSASSA_PSS_params(false, tvb, offset, &asn1_ctx, tree, hf_pkcs1_RSASSA_PSS_params_PDU);
  return offset;
}
static int dissect_ECParameters_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, true, pinfo);
  offset = dissect_pkcs1_ECParameters(false, tvb, offset, &asn1_ctx, tree, hf_pkcs1_ECParameters_PDU);
  return offset;
}
static int dissect_Prime_p_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, true, pinfo);
  offset = dissect_pkcs1_Prime_p(false, tvb, offset, &asn1_ctx, tree, hf_pkcs1_Prime_p_PDU);
  return offset;
}


/*--- proto_register_pkcs1 ----------------------------------------------*/
void proto_register_pkcs1(void) {

  /* List of fields */
  static hf_register_info hf[] = {
    { &hf_pkcs1_DSA_Params_PDU,
      { "DSA-Params", "pkcs1.DSA_Params_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_DomainParameters_PDU,
      { "DomainParameters", "pkcs1.DomainParameters_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_KEA_Params_Id_PDU,
      { "KEA-Params-Id", "pkcs1.KEA_Params_Id",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_HashAlgorithm_PDU,
      { "HashAlgorithm", "pkcs1.HashAlgorithm_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_RSASSA_PSS_params_PDU,
      { "RSASSA-PSS-params", "pkcs1.RSASSA_PSS_params_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_ECParameters_PDU,
      { "ECParameters", "pkcs1.ECParameters",
        FT_UINT32, BASE_DEC, VALS(pkcs1_ECParameters_vals), 0,
        NULL, HFILL }},
    { &hf_pkcs1_Prime_p_PDU,
      { "Prime-p", "pkcs1.Prime_p",
        FT_INT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_modulus,
      { "modulus", "pkcs1.modulus",
        FT_BYTES, BASE_NONE, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_publicExponent,
      { "publicExponent", "pkcs1.publicExponent",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_digestAlgorithm,
      { "digestAlgorithm", "pkcs1.digestAlgorithm_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "DigestAlgorithmIdentifier", HFILL }},
    { &hf_pkcs1_digest,
      { "digest", "pkcs1.digest",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_p,
      { "p", "pkcs1.p",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_q,
      { "q", "pkcs1.q",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_g,
      { "g", "pkcs1.g",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_j,
      { "j", "pkcs1.j",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_validationParams,
      { "validationParams", "pkcs1.validationParams_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_seed,
      { "seed", "pkcs1.seed",
        FT_BYTES, BASE_NONE, NULL, 0,
        "BIT_STRING", HFILL }},
    { &hf_pkcs1_pgenCounter,
      { "pgenCounter", "pkcs1.pgenCounter",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_hashAlgorithm,
      { "hashAlgorithm", "pkcs1.hashAlgorithm_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_maskGenAlgorithm,
      { "maskGenAlgorithm", "pkcs1.maskGenAlgorithm_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_saltLength,
      { "saltLength", "pkcs1.saltLength",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_trailerField,
      { "trailerField", "pkcs1.trailerField",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_specifiedCurve,
      { "specifiedCurve", "pkcs1.specifiedCurve_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "SpecifiedECDomain", HFILL }},
    { &hf_pkcs1_namedCurve,
      { "namedCurve", "pkcs1.namedCurve",
        FT_OID, BASE_NONE, NULL, 0,
        "OBJECT_IDENTIFIER", HFILL }},
    { &hf_pkcs1_version,
      { "version", "pkcs1.version",
        FT_INT32, BASE_DEC, VALS(pkcs1_ECPVer_vals), 0,
        "ECPVer", HFILL }},
    { &hf_pkcs1_fieldID,
      { "fieldID", "pkcs1.fieldID_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_curve,
      { "curve", "pkcs1.curve_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_base,
      { "base", "pkcs1.base",
        FT_BYTES, BASE_NONE, NULL, 0,
        "ECPoint", HFILL }},
    { &hf_pkcs1_order,
      { "order", "pkcs1.order",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_cofactor,
      { "cofactor", "pkcs1.cofactor",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_fieldType,
      { "fieldType", "pkcs1.fieldType",
        FT_OID, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_parameters,
      { "parameters", "pkcs1.parameters_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_pkcs1_a,
      { "a", "pkcs1.a",
        FT_BYTES, BASE_NONE, NULL, 0,
        "FieldElement", HFILL }},
    { &hf_pkcs1_b,
      { "b", "pkcs1.b",
        FT_BYTES, BASE_NONE, NULL, 0,
        "FieldElement", HFILL }},
    { &hf_pkcs1_r,
      { "r", "pkcs1.r",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_pkcs1_s,
      { "s", "pkcs1.s",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
  };

  /* List of subtrees */
  static int *ett[] = {
    &ett_pkcs1_RSAPublicKey,
    &ett_pkcs1_DigestInfo,
    &ett_pkcs1_DSA_Params,
    &ett_pkcs1_DomainParameters,
    &ett_pkcs1_ValidationParams,
    &ett_pkcs1_RSASSA_PSS_params,
    &ett_pkcs1_ECParameters,
    &ett_pkcs1_SpecifiedECDomain,
    &ett_pkcs1_FieldID,
    &ett_pkcs1_Curve,
    &ett_pkcs1_DSA_Sig_Value,
    &ett_pkcs1_ECDSA_Sig_Value,
  };

  /* Register protocol */
  proto_pkcs1 = proto_register_protocol(PNAME, PSNAME, PFNAME);

  /* Register fields and subtrees */
  proto_register_field_array(proto_pkcs1, hf, array_length(hf));
  proto_register_subtree_array(ett, array_length(ett));

}


/*--- proto_reg_handoff_pkcs1 -------------------------------------------*/
void proto_reg_handoff_pkcs1(void) {
  register_ber_oid_dissector("1.2.840.10040.4.1", dissect_DSA_Params_PDU, proto_pkcs1, "id-dsa");
  register_ber_oid_dissector("1.2.840.10046.2.1", dissect_DomainParameters_PDU, proto_pkcs1, "dhpublicnumber");
  register_ber_oid_dissector("2.16.840.1.101.2.1.1.22", dissect_KEA_Params_Id_PDU, proto_pkcs1, "id-keyExchangeAlgorithm");
  register_ber_oid_dissector("1.2.840.10045.2.1", dissect_ECParameters_PDU, proto_pkcs1, "id-ecPublicKey");
  register_ber_oid_dissector("1.3.132.1.12", dissect_ECParameters_PDU, proto_pkcs1, "id-ecDH");
  register_ber_oid_dissector("1.2.840.10045.2.13", dissect_ECParameters_PDU, proto_pkcs1, "id-ecMQV");
  register_ber_oid_dissector("1.2.840.113549.1.1.10", dissect_RSASSA_PSS_params_PDU, proto_pkcs1, "id-RSASSA-PSS");
  register_ber_oid_dissector("1.2.840.113549.1.1.8", dissect_HashAlgorithm_PDU, proto_pkcs1, "id-mgf1");
  register_ber_oid_dissector("1.2.840.10045.1.1", dissect_Prime_p_PDU, proto_pkcs1, "prime-field");


	register_ber_oid_dissector("1.2.840.113549.2.2", dissect_ber_oid_NULL_callback, proto_pkcs1, "md2");
	register_ber_oid_dissector("1.2.840.113549.2.4", dissect_ber_oid_NULL_callback, proto_pkcs1, "md4");
	register_ber_oid_dissector("1.2.840.113549.2.5", dissect_ber_oid_NULL_callback, proto_pkcs1, "md5");

	register_ber_oid_dissector("1.2.840.113549.1.1.1", dissect_ber_oid_NULL_callback, proto_pkcs1, "rsaEncryption");
	register_ber_oid_dissector("1.2.840.113549.1.1.2", dissect_ber_oid_NULL_callback, proto_pkcs1, "md2WithRSAEncryption");
	register_ber_oid_dissector("1.2.840.113549.1.1.3", dissect_ber_oid_NULL_callback, proto_pkcs1, "md4WithRSAEncryption");
	register_ber_oid_dissector("1.2.840.113549.1.1.4", dissect_ber_oid_NULL_callback, proto_pkcs1, "md5WithRSAEncryption");


	/* these two are not from RFC2313  but pulled in from
 	   http://www.alvestrand.no/objectid/1.2.840.113549.1.1.html
	*/
	register_ber_oid_dissector("1.2.840.113549.1.1.5", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha1WithRSAEncryption");
	register_ber_oid_dissector("1.2.840.113549.1.1.6", dissect_ber_oid_NULL_callback, proto_pkcs1, "rsaOAEPEncryptionSET");

	/* these sha2 algorithms are from RFC3447 */
	register_ber_oid_dissector("1.2.840.113549.1.1.11", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha256WithRSAEncryption");
	register_ber_oid_dissector("1.2.840.113549.1.1.12", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha384WithRSAEncryption");
	register_ber_oid_dissector("1.2.840.113549.1.1.13", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha512WithRSAEncryption");
	register_ber_oid_dissector("1.2.840.113549.1.1.14", dissect_ber_oid_NULL_callback, proto_pkcs1, "sha224WithRSAEncryption");

	/* ECDSA SHA-1 algorithm from RFC 3279 */
	register_ber_oid_dissector("1.2.840.10045.4.1", dissect_ber_oid_NULL_callback, proto_pkcs1, "ecdsa-with-SHA1");

	/* SM2-with-SM3 from GM/T 0006 Cryptographic application identifier criterion specification */
	register_ber_oid_dissector("1.2.156.10197.1.501", dissect_ber_oid_NULL_callback, proto_pkcs1, "SM2-with-SM3");

	/* ECDSA SHA2 algorithms from X9.62, RFC5480, RFC 5758, RFC 5912 */
	register_ber_oid_dissector("1.2.840.10045.4.3.1", dissect_ber_oid_NULL_callback, proto_pkcs1, "ecdsa-with-SHA224");
	register_ber_oid_dissector("1.2.840.10045.4.3.2", dissect_ber_oid_NULL_callback, proto_pkcs1, "ecdsa-with-SHA256");
	register_ber_oid_dissector("1.2.840.10045.4.3.3", dissect_ber_oid_NULL_callback, proto_pkcs1, "ecdsa-with-SHA384");
	register_ber_oid_dissector("1.2.840.10045.4.3.4", dissect_ber_oid_NULL_callback, proto_pkcs1, "ecdsa-with-SHA512");

	/* DSA SHA2 algorithms from FIPS186-3, RFC5480, RFC 5758, RFC 5912 */
	register_ber_oid_dissector("2.16.840.1.101.3.4.3.1", dissect_ber_oid_NULL_callback, proto_pkcs1, "id-dsa-with-sha224");
	register_ber_oid_dissector("2.16.840.1.101.3.4.3.2", dissect_ber_oid_NULL_callback, proto_pkcs1, "id-dsa-with-sha256");

	oid_add_from_string("secp192r1","1.2.840.10045.3.1.1");
	oid_add_from_string("sect163k1","1.3.132.0.1");
	oid_add_from_string("sect163r2","1.3.132.0.15");
	oid_add_from_string("secp224r1","1.3.132.0.33");
	oid_add_from_string("sect233k1","1.3.132.0.26");
	oid_add_from_string("sect233r1","1.3.132.0.27");
	oid_add_from_string("secp256r1","1.2.840.10045.3.1.7");
	oid_add_from_string("sect283k1","1.3.132.0.16");
	oid_add_from_string("sect283r1","1.3.132.0.17");
	oid_add_from_string("secp384r1","1.3.132.0.34");
	oid_add_from_string("sect409k1","1.3.132.0.36");
	oid_add_from_string("sect409r1","1.3.132.0.37");
	oid_add_from_string("secp521r1","1.3.132.0.35");
	oid_add_from_string("sect571k1","1.3.132.0.38");
	oid_add_from_string("sect571r1","1.3.132.0.39");

	/* SM2 from GM/T 0006 Cryptographic application identifier criterion specification */
	oid_add_from_string("sm2","1.2.156.10197.1.301");

	/* sha2 family, see RFC3447 and http://www.oid-info.com/get/2.16.840.1.101.3.4.2 */
	oid_add_from_string("sha256", "2.16.840.1.101.3.4.2.1");
	oid_add_from_string("sha384", "2.16.840.1.101.3.4.2.2");
	oid_add_from_string("sha512", "2.16.840.1.101.3.4.2.3");
	oid_add_from_string("sha224", "2.16.840.1.101.3.4.2.4");

	/* SM3 from GM/T 0006 Cryptographic application identifier criterion specification */
	oid_add_from_string("sm3","1.2.156.10197.1.401");

	/* PQC digital signature algorithms from OQS-OpenSSL,
		see https://github.com/open-quantum-safe/openssl/blob/OQS-OpenSSL_1_1_1-stable/oqs-template/oqs-sig-info.md */
	oid_add_from_string("dilithium2", "1.3.6.1.4.1.2.267.7.4.4");
	oid_add_from_string("p256_dilithium2", "1.3.9999.2.7.1");
	oid_add_from_string("rsa3072_dilithium2", "1.3.9999.2.7.2");
	oid_add_from_string("dilithium3", "1.3.6.1.4.1.2.267.7.6.5");
	oid_add_from_string("p384_dilithium3", "1.3.9999.2.7.3");
	oid_add_from_string("dilithium5", "1.3.6.1.4.1.2.267.7.8.7");
	oid_add_from_string("p521_dilithium5", "1.3.9999.2.7.4");
	oid_add_from_string("dilithium2_aes", "1.3.6.1.4.1.2.267.11.4.4");
	oid_add_from_string("p256_dilithium2_aes", "1.3.9999.2.11.1");
	oid_add_from_string("rsa3072_dilithium2_aes", "1.3.9999.2.11.2");
	oid_add_from_string("dilithium3_aes", "1.3.6.1.4.1.2.267.11.6.5");
	oid_add_from_string("p384_dilithium3_aes", "1.3.9999.2.11.3");
	oid_add_from_string("dilithium5_aes", "1.3.6.1.4.1.2.267.11.8.7");
	oid_add_from_string("p521_dilithium5_aes", "1.3.9999.2.11.4");
	oid_add_from_string("falcon512", "1.3.9999.3.1");
	oid_add_from_string("p256_falcon512", "1.3.9999.3.2");
	oid_add_from_string("rsa3072_falcon512", "1.3.9999.3.3");
	oid_add_from_string("falcon1024", "1.3.9999.3.4");
	oid_add_from_string("p521_falcon1024", "1.3.9999.3.5");
	oid_add_from_string("picnicl1full", "1.3.6.1.4.1.311.89.2.1.7");
	oid_add_from_string("p256_picnicl1full", "1.3.6.1.4.1.311.89.2.1.8");
	oid_add_from_string("rsa3072_picnicl1full", "1.3.6.1.4.1.311.89.2.1.9");
	oid_add_from_string("picnic3l1", "1.3.6.1.4.1.311.89.2.1.21");
	oid_add_from_string("p256_picnic3l1", "1.3.6.1.4.1.311.89.2.1.22");
	oid_add_from_string("rsa3072_picnic3l1", "1.3.6.1.4.1.311.89.2.1.23");
	oid_add_from_string("rainbowIclassic", "1.3.9999.5.1.1.1");
	oid_add_from_string("p256_rainbowIclassic", "1.3.9999.5.1.2.1");
	oid_add_from_string("rsa3072_rainbowIclassic", "1.3.9999.5.1.3.1");
	oid_add_from_string("rainbowVclassic", "1.3.9999.5.3.1.1");
	oid_add_from_string("p521_rainbowVclassic", "1.3.9999.5.3.2.1");
	oid_add_from_string("sphincsharaka128frobust", "1.3.9999.6.1.1");
	oid_add_from_string("p256_sphincsharaka128frobust", "1.3.9999.6.1.2");
	oid_add_from_string("rsa3072_sphincsharaka128frobust", "1.3.9999.6.1.3");
	oid_add_from_string("sphincssha256128frobust", "1.3.9999.6.4.1");
	oid_add_from_string("p256_sphincssha256128frobust", "1.3.9999.6.4.2");
	oid_add_from_string("rsa3072_sphincssha256128frobust", "1.3.9999.6.4.3");
	oid_add_from_string("sphincsshake256128frobust", "1.3.9999.6.7.1");
	oid_add_from_string("p256_sphincsshake256128frobust", "1.3.9999.6.7.2");
	oid_add_from_string("rsa3072_sphincsshake256128frobust", "1.3.9999.6.7.3");

}

