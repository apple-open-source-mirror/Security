//   NOTE: this is a machine generated file--editing not recommended
//
// pkcs10.cpp - class member functions for ASN.1 module PKCS5
//
//   This file was generated by snacc on Mon Apr 22 22:34:19 2002
//   UBC snacc written by Mike Sample
//   A couple of enhancements made by IBM European Networking Center


#include "asn-incl.h"
#include "sm_vdatypes.h"
#include "sm_x501ud.h"
#include "sm_x411ub.h"
#include "sm_x411mtsas.h"
#include "sm_x501if.h"
#include "sm_x520sa.h"
#include "sm_x509cmn.h"
#include "sm_x509af.h"
#include "sm_x509ce.h"
#include "pkcs1oids.h"
#include "pkcs9oids.h"
#include "sm_cms.h"
#include "sm_ess.h"
#include "pkcs7.h"
#include "pkcs8.h"
#include "appleoids.h"
#include "pkcs10.h"

//------------------------------------------------------------------------------
// value defs


//------------------------------------------------------------------------------
// class member definitions:

CertificationRequestInfo::CertificationRequestInfo()
{
#if TCL
  subject = new Name;
#else
  subject = NULL; // incomplete initialization of mandatory element!
#endif // TCL
#if TCL
  subjectPublicKeyInfo = new SubjectPublicKeyInfo;
#else
  subjectPublicKeyInfo = NULL; // incomplete initialization of mandatory element!
#endif // TCL
}

CertificationRequestInfo::CertificationRequestInfo (const CertificationRequestInfo &)
{
  Asn1Error << "use of incompletely defined CertificationRequestInfo::CertificationRequestInfo (const CertificationRequestInfo &)" << endl;
  abort();
}

CertificationRequestInfo::~CertificationRequestInfo()
{
  delete subject;
  delete subjectPublicKeyInfo;
}

AsnType *CertificationRequestInfo::Clone() const
{
  return new CertificationRequestInfo;
}

AsnType *CertificationRequestInfo::Copy() const
{
  return new CertificationRequestInfo (*this);
}

#if SNACC_DEEP_COPY
CertificationRequestInfo &CertificationRequestInfo::operator = (const CertificationRequestInfo &that)
#else // SNACC_DEEP_COPY
CertificationRequestInfo &CertificationRequestInfo::operator = (const CertificationRequestInfo &)
#endif // SNACC_DEEP_COPY
{
#if SNACC_DEEP_COPY
  if (this != &that)
  {
    version = that.version;
    if (that.subject)
    {
      if (!subject)
        subject = new Name;
      *subject = *that.subject;
    }
    else
    {
      delete subject;
      subject = NULL;
    }
    if (that.subjectPublicKeyInfo)
    {
      if (!subjectPublicKeyInfo)
        subjectPublicKeyInfo = new SubjectPublicKeyInfo;
      *subjectPublicKeyInfo = *that.subjectPublicKeyInfo;
    }
    else
    {
      delete subjectPublicKeyInfo;
      subjectPublicKeyInfo = NULL;
    }
    attributes = that.attributes;
  }

  return *this;
#else // SNACC_DEEP_COPY
  Asn1Error << "use of incompletely defined CertificationRequestInfo &CertificationRequestInfo::operator = (const CertificationRequestInfo &)" << endl;
  abort();
  // if your compiler complains here, check the -novolat option
#endif // SNACC_DEEP_COPY
}

AsnLen
CertificationRequestInfo::BEncContent (BUF_TYPE b)
{
  AsnLen totalLen = 0;
  AsnLen l;

      BEncEocIfNec (b);
    l = attributes.BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 0);
    totalLen += l;

      BEncEocIfNec (b);
    l = subjectPublicKeyInfo->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
    totalLen += l;

    l = subject->BEncContent (b);
    totalLen += l;

    l = version.BEncContent (b);
    BEncDefLenTo127 (b, l);
    l++;

    l += BEncTag1 (b, UNIV, PRIM, INTEGER_TAG_CODE);
    totalLen += l;

  return totalLen;
} // CertificationRequestInfo::BEncContent


void CertificationRequestInfo::BDecContent (BUF_TYPE b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  tag1 = BDecTag (b, seqBytesDecoded, env);

  if ((tag1 == MAKE_TAG_ID (UNIV, PRIM, INTEGER_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    version.BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-100);
  }

  if ((tag1 == MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    subject = new Name;
    subject->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-101);
  }

  if ((tag1 == MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    subjectPublicKeyInfo = new SubjectPublicKeyInfo;
    subjectPublicKeyInfo->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-102);
  }

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 0)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    attributes.BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-103);
  }

  bytesDecoded += seqBytesDecoded;
  if (elmtLen0 == INDEFINITE_LEN)
  {
    BDecEoc (b, bytesDecoded, env);
    return;
  }
  else if (seqBytesDecoded != elmtLen0)
  {
    Asn1Error << "ERROR - Length discrepancy on sequence." << endl;
    SnaccExcep::throwMe(-104);
  }
  else
    return;
} // CertificationRequestInfo::BDecContent

AsnLen CertificationRequestInfo::BEnc (BUF_TYPE b)
{
  AsnLen l;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void CertificationRequestInfo::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    Asn1Error << "CertificationRequestInfo::BDec: ERROR - wrong tag" << endl;
    SnaccExcep::throwMe(-105);
  }
  elmtLen1 = BDecLen (b, bytesDecoded, env);
  BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

void CertificationRequestInfo::Print (ostream &os) const
{
#ifndef NDEBUG
  os << "{ -- SEQUENCE --" << endl;
  indentG += stdIndentG;

  {
    Indent (os, indentG);
    os << "version ";
    os << version;
    os << "," << endl;
  }

  if (NOT_NULL (subject))
  {
    Indent (os, indentG);
    os << "subject ";
    os << *subject;
  }
  else
  {
    Indent (os, indentG);
    os << "subject ";
    os << "-- void --";
    os << "," << endl;
  }

  if (NOT_NULL (subjectPublicKeyInfo))
  {
    Indent (os, indentG);
    os << "subjectPublicKeyInfo ";
    os << *subjectPublicKeyInfo;
  }
  else
  {
    Indent (os, indentG);
    os << "subjectPublicKeyInfo ";
    os << "-- void --";
    os << "," << endl;
  }

  {
    Indent (os, indentG);
    os << "attributes ";
    os << attributes;
  }

  os << endl;
  indentG -= stdIndentG;
  Indent (os, indentG);
  os << "}";
#endif /* NDEBUG */
} // CertificationRequestInfo::Print


CertificationRequest::CertificationRequest()
{
#if TCL
  certificationRequestInfo = new CertificationRequestInfo;
#else
  certificationRequestInfo = NULL; // incomplete initialization of mandatory element!
#endif // TCL
#if TCL
  signatureAlgorithm = new SignatureAlgorithmIdentifier;
#else
  signatureAlgorithm = NULL; // incomplete initialization of mandatory element!
#endif // TCL
}

CertificationRequest::CertificationRequest (const CertificationRequest &)
{
  Asn1Error << "use of incompletely defined CertificationRequest::CertificationRequest (const CertificationRequest &)" << endl;
  abort();
}

CertificationRequest::~CertificationRequest()
{
  delete certificationRequestInfo;
  delete signatureAlgorithm;
}

AsnType *CertificationRequest::Clone() const
{
  return new CertificationRequest;
}

AsnType *CertificationRequest::Copy() const
{
  return new CertificationRequest (*this);
}

#if SNACC_DEEP_COPY
CertificationRequest &CertificationRequest::operator = (const CertificationRequest &that)
#else // SNACC_DEEP_COPY
CertificationRequest &CertificationRequest::operator = (const CertificationRequest &)
#endif // SNACC_DEEP_COPY
{
#if SNACC_DEEP_COPY
  if (this != &that)
  {
    if (that.certificationRequestInfo)
    {
      if (!certificationRequestInfo)
        certificationRequestInfo = new CertificationRequestInfo;
      *certificationRequestInfo = *that.certificationRequestInfo;
    }
    else
    {
      delete certificationRequestInfo;
      certificationRequestInfo = NULL;
    }
    if (that.signatureAlgorithm)
    {
      if (!signatureAlgorithm)
        signatureAlgorithm = new SignatureAlgorithmIdentifier;
      *signatureAlgorithm = *that.signatureAlgorithm;
    }
    else
    {
      delete signatureAlgorithm;
      signatureAlgorithm = NULL;
    }
    signature = that.signature;
  }

  return *this;
#else // SNACC_DEEP_COPY
  Asn1Error << "use of incompletely defined CertificationRequest &CertificationRequest::operator = (const CertificationRequest &)" << endl;
  abort();
  // if your compiler complains here, check the -novolat option
#endif // SNACC_DEEP_COPY
}

AsnLen
CertificationRequest::BEncContent (BUF_TYPE b)
{
  AsnLen totalLen = 0;
  AsnLen l;

    l = signature.BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, BITSTRING_TAG_CODE);
    totalLen += l;

      BEncEocIfNec (b);
    l = signatureAlgorithm->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
    totalLen += l;

      BEncEocIfNec (b);
    l = certificationRequestInfo->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
    totalLen += l;

  return totalLen;
} // CertificationRequest::BEncContent


void CertificationRequest::BDecContent (BUF_TYPE b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  tag1 = BDecTag (b, seqBytesDecoded, env);

  if ((tag1 == MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    certificationRequestInfo = new CertificationRequestInfo;
    certificationRequestInfo->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-106);
  }

  if ((tag1 == MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    signatureAlgorithm = new SignatureAlgorithmIdentifier;
    signatureAlgorithm->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-107);
  }

  if ((tag1 == MAKE_TAG_ID (UNIV, PRIM, BITSTRING_TAG_CODE))
    || (tag1 == MAKE_TAG_ID (UNIV, CONS, BITSTRING_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    signature.BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-108);
  }

  bytesDecoded += seqBytesDecoded;
  if (elmtLen0 == INDEFINITE_LEN)
  {
    BDecEoc (b, bytesDecoded, env);
    return;
  }
  else if (seqBytesDecoded != elmtLen0)
  {
    Asn1Error << "ERROR - Length discrepancy on sequence." << endl;
    SnaccExcep::throwMe(-109);
  }
  else
    return;
} // CertificationRequest::BDecContent

AsnLen CertificationRequest::BEnc (BUF_TYPE b)
{
  AsnLen l;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void CertificationRequest::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    Asn1Error << "CertificationRequest::BDec: ERROR - wrong tag" << endl;
    SnaccExcep::throwMe(-110);
  }
  elmtLen1 = BDecLen (b, bytesDecoded, env);
  BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

void CertificationRequest::Print (ostream &os) const
{
#ifndef NDEBUG
  os << "{ -- SEQUENCE --" << endl;
  indentG += stdIndentG;

  if (NOT_NULL (certificationRequestInfo))
  {
    Indent (os, indentG);
    os << "certificationRequestInfo ";
    os << *certificationRequestInfo;
  }
  else
  {
    Indent (os, indentG);
    os << "certificationRequestInfo ";
    os << "-- void --";
    os << "," << endl;
  }

  if (NOT_NULL (signatureAlgorithm))
  {
    Indent (os, indentG);
    os << "signatureAlgorithm ";
    os << *signatureAlgorithm;
  }
  else
  {
    Indent (os, indentG);
    os << "signatureAlgorithm ";
    os << "-- void --";
    os << "," << endl;
  }

  {
    Indent (os, indentG);
    os << "signature ";
    os << signature;
  }

  os << endl;
  indentG -= stdIndentG;
  Indent (os, indentG);
  os << "}";
#endif /* NDEBUG */
} // CertificationRequest::Print


CertificationRequestSigned::CertificationRequestSigned()
{
#if TCL
  signatureAlgorithm = new SignatureAlgorithmIdentifier;
#else
  signatureAlgorithm = NULL; // incomplete initialization of mandatory element!
#endif // TCL
}

CertificationRequestSigned::CertificationRequestSigned (const CertificationRequestSigned &)
{
  Asn1Error << "use of incompletely defined CertificationRequestSigned::CertificationRequestSigned (const CertificationRequestSigned &)" << endl;
  abort();
}

CertificationRequestSigned::~CertificationRequestSigned()
{
  delete signatureAlgorithm;
}

AsnType *CertificationRequestSigned::Clone() const
{
  return new CertificationRequestSigned;
}

AsnType *CertificationRequestSigned::Copy() const
{
  return new CertificationRequestSigned (*this);
}

#if SNACC_DEEP_COPY
CertificationRequestSigned &CertificationRequestSigned::operator = (const CertificationRequestSigned &that)
#else // SNACC_DEEP_COPY
CertificationRequestSigned &CertificationRequestSigned::operator = (const CertificationRequestSigned &)
#endif // SNACC_DEEP_COPY
{
#if SNACC_DEEP_COPY
  if (this != &that)
  {
    certificationRequestInfo = that.certificationRequestInfo;
    if (that.signatureAlgorithm)
    {
      if (!signatureAlgorithm)
        signatureAlgorithm = new SignatureAlgorithmIdentifier;
      *signatureAlgorithm = *that.signatureAlgorithm;
    }
    else
    {
      delete signatureAlgorithm;
      signatureAlgorithm = NULL;
    }
    signature = that.signature;
  }

  return *this;
#else // SNACC_DEEP_COPY
  Asn1Error << "use of incompletely defined CertificationRequestSigned &CertificationRequestSigned::operator = (const CertificationRequestSigned &)" << endl;
  abort();
  // if your compiler complains here, check the -novolat option
#endif // SNACC_DEEP_COPY
}

AsnLen
CertificationRequestSigned::BEncContent (BUF_TYPE b)
{
  AsnLen totalLen = 0;
  AsnLen l;

    l = signature.BEncContent (b);
    l += BEncDefLen (b, l);

    l += BEncTag1 (b, UNIV, PRIM, BITSTRING_TAG_CODE);
    totalLen += l;

      BEncEocIfNec (b);
    l = signatureAlgorithm->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
    totalLen += l;

        ENC_LOAD_ANYBUF(&certificationRequestInfo, b, l);
    totalLen += l;

  return totalLen;
} // CertificationRequestSigned::BEncContent


void CertificationRequestSigned::BDecContent (BUF_TYPE b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  // ANY type
        DEC_LOAD_ANYBUF(&certificationRequestInfo, b, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);


  if ((tag1 == MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    signatureAlgorithm = new SignatureAlgorithmIdentifier;
    signatureAlgorithm->BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
    tag1 = BDecTag (b, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-111);
  }

  if ((tag1 == MAKE_TAG_ID (UNIV, PRIM, BITSTRING_TAG_CODE))
    || (tag1 == MAKE_TAG_ID (UNIV, CONS, BITSTRING_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded, env);
    signature.BDecContent (b, tag1, elmtLen1, seqBytesDecoded, env);
  }
  else
  {
    Asn1Error << "ERROR - SEQUENCE is missing non-optional elmt." << endl;
    SnaccExcep::throwMe(-112);
  }

  bytesDecoded += seqBytesDecoded;
  if (elmtLen0 == INDEFINITE_LEN)
  {
    BDecEoc (b, bytesDecoded, env);
    return;
  }
  else if (seqBytesDecoded != elmtLen0)
  {
    Asn1Error << "ERROR - Length discrepancy on sequence." << endl;
    SnaccExcep::throwMe(-113);
  }
  else
    return;
} // CertificationRequestSigned::BDecContent

AsnLen CertificationRequestSigned::BEnc (BUF_TYPE b)
{
  AsnLen l;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void CertificationRequestSigned::BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env)
{
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded, env)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    Asn1Error << "CertificationRequestSigned::BDec: ERROR - wrong tag" << endl;
    SnaccExcep::throwMe(-114);
  }
  elmtLen1 = BDecLen (b, bytesDecoded, env);
  BDecContent (b, tag, elmtLen1, bytesDecoded, env);
}

void CertificationRequestSigned::Print (ostream &os) const
{
#ifndef NDEBUG
  os << "{ -- SEQUENCE --" << endl;
  indentG += stdIndentG;

  {
    Indent (os, indentG);
    os << "certificationRequestInfo ";
    os << certificationRequestInfo;
    os << "," << endl;
  }

  if (NOT_NULL (signatureAlgorithm))
  {
    Indent (os, indentG);
    os << "signatureAlgorithm ";
    os << *signatureAlgorithm;
  }
  else
  {
    Indent (os, indentG);
    os << "signatureAlgorithm ";
    os << "-- void --";
    os << "," << endl;
  }

  {
    Indent (os, indentG);
    os << "signature ";
    os << signature;
  }

  os << endl;
  indentG -= stdIndentG;
  Indent (os, indentG);
  os << "}";
#endif /* NDEBUG */
} // CertificationRequestSigned::Print


