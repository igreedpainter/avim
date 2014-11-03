// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: avim-base.proto

#ifndef PROTOBUF_avim_2dbase_2eproto__INCLUDED
#define PROTOBUF_avim_2dbase_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace proto {
namespace base {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_avim_2dbase_2eproto();
void protobuf_AssignDesc_avim_2dbase_2eproto();
void protobuf_ShutdownFile_avim_2dbase_2eproto();

class avAddress;
class avPacket;
class aGMP;
class avTCPPacket;

// ===================================================================

class avAddress : public ::google::protobuf::Message {
 public:
  avAddress();
  virtual ~avAddress();

  avAddress(const avAddress& from);

  inline avAddress& operator=(const avAddress& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const avAddress& default_instance();

  void Swap(avAddress* other);

  // implements Message ----------------------------------------------

  avAddress* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const avAddress& from);
  void MergeFrom(const avAddress& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string username = 1;
  inline bool has_username() const;
  inline void clear_username();
  static const int kUsernameFieldNumber = 1;
  inline const ::std::string& username() const;
  inline void set_username(const ::std::string& value);
  inline void set_username(const char* value);
  inline void set_username(const char* value, size_t size);
  inline ::std::string* mutable_username();
  inline ::std::string* release_username();
  inline void set_allocated_username(::std::string* username);

  // required string domain = 2;
  inline bool has_domain() const;
  inline void clear_domain();
  static const int kDomainFieldNumber = 2;
  inline const ::std::string& domain() const;
  inline void set_domain(const ::std::string& value);
  inline void set_domain(const char* value);
  inline void set_domain(const char* value, size_t size);
  inline ::std::string* mutable_domain();
  inline ::std::string* release_domain();
  inline void set_allocated_domain(::std::string* domain);

  // optional string resource = 3;
  inline bool has_resource() const;
  inline void clear_resource();
  static const int kResourceFieldNumber = 3;
  inline const ::std::string& resource() const;
  inline void set_resource(const ::std::string& value);
  inline void set_resource(const char* value);
  inline void set_resource(const char* value, size_t size);
  inline ::std::string* mutable_resource();
  inline ::std::string* release_resource();
  inline void set_allocated_resource(::std::string* resource);

  // @@protoc_insertion_point(class_scope:proto.base.avAddress)
 private:
  inline void set_has_username();
  inline void clear_has_username();
  inline void set_has_domain();
  inline void clear_has_domain();
  inline void set_has_resource();
  inline void clear_has_resource();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* username_;
  ::std::string* domain_;
  ::std::string* resource_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_avim_2dbase_2eproto();
  friend void protobuf_AssignDesc_avim_2dbase_2eproto();
  friend void protobuf_ShutdownFile_avim_2dbase_2eproto();

  void InitAsDefaultInstance();
  static avAddress* default_instance_;
};
// -------------------------------------------------------------------

class avPacket : public ::google::protobuf::Message {
 public:
  avPacket();
  virtual ~avPacket();

  avPacket(const avPacket& from);

  inline avPacket& operator=(const avPacket& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const avPacket& default_instance();

  void Swap(avPacket* other);

  // implements Message ----------------------------------------------

  avPacket* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const avPacket& from);
  void MergeFrom(const avPacket& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .proto.base.avAddress src = 1;
  inline bool has_src() const;
  inline void clear_src();
  static const int kSrcFieldNumber = 1;
  inline const ::proto::base::avAddress& src() const;
  inline ::proto::base::avAddress* mutable_src();
  inline ::proto::base::avAddress* release_src();
  inline void set_allocated_src(::proto::base::avAddress* src);

  // required .proto.base.avAddress dest = 2;
  inline bool has_dest() const;
  inline void clear_dest();
  static const int kDestFieldNumber = 2;
  inline const ::proto::base::avAddress& dest() const;
  inline ::proto::base::avAddress* mutable_dest();
  inline ::proto::base::avAddress* release_dest();
  inline void set_allocated_dest(::proto::base::avAddress* dest);

  // required bytes figurprint = 3;
  inline bool has_figurprint() const;
  inline void clear_figurprint();
  static const int kFigurprintFieldNumber = 3;
  inline const ::std::string& figurprint() const;
  inline void set_figurprint(const ::std::string& value);
  inline void set_figurprint(const char* value);
  inline void set_figurprint(const void* value, size_t size);
  inline ::std::string* mutable_figurprint();
  inline ::std::string* release_figurprint();
  inline void set_allocated_figurprint(::std::string* figurprint);

  // required string upperlayerpotocol = 6 [default = "avim"];
  inline bool has_upperlayerpotocol() const;
  inline void clear_upperlayerpotocol();
  static const int kUpperlayerpotocolFieldNumber = 6;
  inline const ::std::string& upperlayerpotocol() const;
  inline void set_upperlayerpotocol(const ::std::string& value);
  inline void set_upperlayerpotocol(const char* value);
  inline void set_upperlayerpotocol(const char* value, size_t size);
  inline ::std::string* mutable_upperlayerpotocol();
  inline ::std::string* release_upperlayerpotocol();
  inline void set_allocated_upperlayerpotocol(::std::string* upperlayerpotocol);

  // optional uint32 encrype_method = 7;
  inline bool has_encrype_method() const;
  inline void clear_encrype_method();
  static const int kEncrypeMethodFieldNumber = 7;
  inline ::google::protobuf::uint32 encrype_method() const;
  inline void set_encrype_method(::google::protobuf::uint32 value);

  // optional bytes payload = 8;
  inline bool has_payload() const;
  inline void clear_payload();
  static const int kPayloadFieldNumber = 8;
  inline const ::std::string& payload() const;
  inline void set_payload(const ::std::string& value);
  inline void set_payload(const char* value);
  inline void set_payload(const void* value, size_t size);
  inline ::std::string* mutable_payload();
  inline ::std::string* release_payload();
  inline void set_allocated_payload(::std::string* payload);

  // @@protoc_insertion_point(class_scope:proto.base.avPacket)
 private:
  inline void set_has_src();
  inline void clear_has_src();
  inline void set_has_dest();
  inline void clear_has_dest();
  inline void set_has_figurprint();
  inline void clear_has_figurprint();
  inline void set_has_upperlayerpotocol();
  inline void clear_has_upperlayerpotocol();
  inline void set_has_encrype_method();
  inline void clear_has_encrype_method();
  inline void set_has_payload();
  inline void clear_has_payload();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::proto::base::avAddress* src_;
  ::proto::base::avAddress* dest_;
  ::std::string* figurprint_;
  ::std::string* upperlayerpotocol_;
  static ::std::string* _default_upperlayerpotocol_;
  ::std::string* payload_;
  ::google::protobuf::uint32 encrype_method_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  friend void  protobuf_AddDesc_avim_2dbase_2eproto();
  friend void protobuf_AssignDesc_avim_2dbase_2eproto();
  friend void protobuf_ShutdownFile_avim_2dbase_2eproto();

  void InitAsDefaultInstance();
  static avPacket* default_instance_;
};
// -------------------------------------------------------------------

class aGMP : public ::google::protobuf::Message {
 public:
  aGMP();
  virtual ~aGMP();

  aGMP(const aGMP& from);

  inline aGMP& operator=(const aGMP& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const aGMP& default_instance();

  void Swap(aGMP* other);

  // implements Message ----------------------------------------------

  aGMP* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const aGMP& from);
  void MergeFrom(const aGMP& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:proto.base.aGMP)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_avim_2dbase_2eproto();
  friend void protobuf_AssignDesc_avim_2dbase_2eproto();
  friend void protobuf_ShutdownFile_avim_2dbase_2eproto();

  void InitAsDefaultInstance();
  static aGMP* default_instance_;
};
// -------------------------------------------------------------------

class avTCPPacket : public ::google::protobuf::Message {
 public:
  avTCPPacket();
  virtual ~avTCPPacket();

  avTCPPacket(const avTCPPacket& from);

  inline avTCPPacket& operator=(const avTCPPacket& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const avTCPPacket& default_instance();

  void Swap(avTCPPacket* other);

  // implements Message ----------------------------------------------

  avTCPPacket* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const avTCPPacket& from);
  void MergeFrom(const avTCPPacket& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::uint32 type() const;
  inline void set_type(::google::protobuf::uint32 value);

  // optional .proto.base.avPacket avpacket = 2;
  inline bool has_avpacket() const;
  inline void clear_avpacket();
  static const int kAvpacketFieldNumber = 2;
  inline const ::proto::base::avPacket& avpacket() const;
  inline ::proto::base::avPacket* mutable_avpacket();
  inline ::proto::base::avPacket* release_avpacket();
  inline void set_allocated_avpacket(::proto::base::avPacket* avpacket);

  // optional .proto.base.avAddress endpoint_address = 3;
  inline bool has_endpoint_address() const;
  inline void clear_endpoint_address();
  static const int kEndpointAddressFieldNumber = 3;
  inline const ::proto::base::avAddress& endpoint_address() const;
  inline ::proto::base::avAddress* mutable_endpoint_address();
  inline ::proto::base::avAddress* release_endpoint_address();
  inline void set_allocated_endpoint_address(::proto::base::avAddress* endpoint_address);

  // optional bytes endpoint_cert = 4;
  inline bool has_endpoint_cert() const;
  inline void clear_endpoint_cert();
  static const int kEndpointCertFieldNumber = 4;
  inline const ::std::string& endpoint_cert() const;
  inline void set_endpoint_cert(const ::std::string& value);
  inline void set_endpoint_cert(const char* value);
  inline void set_endpoint_cert(const void* value, size_t size);
  inline ::std::string* mutable_endpoint_cert();
  inline ::std::string* release_endpoint_cert();
  inline void set_allocated_endpoint_cert(::std::string* endpoint_cert);

  // @@protoc_insertion_point(class_scope:proto.base.avTCPPacket)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_avpacket();
  inline void clear_has_avpacket();
  inline void set_has_endpoint_address();
  inline void clear_has_endpoint_address();
  inline void set_has_endpoint_cert();
  inline void clear_has_endpoint_cert();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::proto::base::avPacket* avpacket_;
  ::proto::base::avAddress* endpoint_address_;
  ::std::string* endpoint_cert_;
  ::google::protobuf::uint32 type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_avim_2dbase_2eproto();
  friend void protobuf_AssignDesc_avim_2dbase_2eproto();
  friend void protobuf_ShutdownFile_avim_2dbase_2eproto();

  void InitAsDefaultInstance();
  static avTCPPacket* default_instance_;
};
// ===================================================================


// ===================================================================

// avAddress

// required string username = 1;
inline bool avAddress::has_username() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void avAddress::set_has_username() {
  _has_bits_[0] |= 0x00000001u;
}
inline void avAddress::clear_has_username() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void avAddress::clear_username() {
  if (username_ != &::google::protobuf::internal::kEmptyString) {
    username_->clear();
  }
  clear_has_username();
}
inline const ::std::string& avAddress::username() const {
  return *username_;
}
inline void avAddress::set_username(const ::std::string& value) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(value);
}
inline void avAddress::set_username(const char* value) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(value);
}
inline void avAddress::set_username(const char* value, size_t size) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* avAddress::mutable_username() {
  set_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  return username_;
}
inline ::std::string* avAddress::release_username() {
  clear_has_username();
  if (username_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = username_;
    username_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void avAddress::set_allocated_username(::std::string* username) {
  if (username_ != &::google::protobuf::internal::kEmptyString) {
    delete username_;
  }
  if (username) {
    set_has_username();
    username_ = username;
  } else {
    clear_has_username();
    username_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string domain = 2;
inline bool avAddress::has_domain() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void avAddress::set_has_domain() {
  _has_bits_[0] |= 0x00000002u;
}
inline void avAddress::clear_has_domain() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void avAddress::clear_domain() {
  if (domain_ != &::google::protobuf::internal::kEmptyString) {
    domain_->clear();
  }
  clear_has_domain();
}
inline const ::std::string& avAddress::domain() const {
  return *domain_;
}
inline void avAddress::set_domain(const ::std::string& value) {
  set_has_domain();
  if (domain_ == &::google::protobuf::internal::kEmptyString) {
    domain_ = new ::std::string;
  }
  domain_->assign(value);
}
inline void avAddress::set_domain(const char* value) {
  set_has_domain();
  if (domain_ == &::google::protobuf::internal::kEmptyString) {
    domain_ = new ::std::string;
  }
  domain_->assign(value);
}
inline void avAddress::set_domain(const char* value, size_t size) {
  set_has_domain();
  if (domain_ == &::google::protobuf::internal::kEmptyString) {
    domain_ = new ::std::string;
  }
  domain_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* avAddress::mutable_domain() {
  set_has_domain();
  if (domain_ == &::google::protobuf::internal::kEmptyString) {
    domain_ = new ::std::string;
  }
  return domain_;
}
inline ::std::string* avAddress::release_domain() {
  clear_has_domain();
  if (domain_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = domain_;
    domain_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void avAddress::set_allocated_domain(::std::string* domain) {
  if (domain_ != &::google::protobuf::internal::kEmptyString) {
    delete domain_;
  }
  if (domain) {
    set_has_domain();
    domain_ = domain;
  } else {
    clear_has_domain();
    domain_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string resource = 3;
inline bool avAddress::has_resource() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void avAddress::set_has_resource() {
  _has_bits_[0] |= 0x00000004u;
}
inline void avAddress::clear_has_resource() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void avAddress::clear_resource() {
  if (resource_ != &::google::protobuf::internal::kEmptyString) {
    resource_->clear();
  }
  clear_has_resource();
}
inline const ::std::string& avAddress::resource() const {
  return *resource_;
}
inline void avAddress::set_resource(const ::std::string& value) {
  set_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    resource_ = new ::std::string;
  }
  resource_->assign(value);
}
inline void avAddress::set_resource(const char* value) {
  set_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    resource_ = new ::std::string;
  }
  resource_->assign(value);
}
inline void avAddress::set_resource(const char* value, size_t size) {
  set_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    resource_ = new ::std::string;
  }
  resource_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* avAddress::mutable_resource() {
  set_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    resource_ = new ::std::string;
  }
  return resource_;
}
inline ::std::string* avAddress::release_resource() {
  clear_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = resource_;
    resource_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void avAddress::set_allocated_resource(::std::string* resource) {
  if (resource_ != &::google::protobuf::internal::kEmptyString) {
    delete resource_;
  }
  if (resource) {
    set_has_resource();
    resource_ = resource;
  } else {
    clear_has_resource();
    resource_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// avPacket

// required .proto.base.avAddress src = 1;
inline bool avPacket::has_src() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void avPacket::set_has_src() {
  _has_bits_[0] |= 0x00000001u;
}
inline void avPacket::clear_has_src() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void avPacket::clear_src() {
  if (src_ != NULL) src_->::proto::base::avAddress::Clear();
  clear_has_src();
}
inline const ::proto::base::avAddress& avPacket::src() const {
  return src_ != NULL ? *src_ : *default_instance_->src_;
}
inline ::proto::base::avAddress* avPacket::mutable_src() {
  set_has_src();
  if (src_ == NULL) src_ = new ::proto::base::avAddress;
  return src_;
}
inline ::proto::base::avAddress* avPacket::release_src() {
  clear_has_src();
  ::proto::base::avAddress* temp = src_;
  src_ = NULL;
  return temp;
}
inline void avPacket::set_allocated_src(::proto::base::avAddress* src) {
  delete src_;
  src_ = src;
  if (src) {
    set_has_src();
  } else {
    clear_has_src();
  }
}

// required .proto.base.avAddress dest = 2;
inline bool avPacket::has_dest() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void avPacket::set_has_dest() {
  _has_bits_[0] |= 0x00000002u;
}
inline void avPacket::clear_has_dest() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void avPacket::clear_dest() {
  if (dest_ != NULL) dest_->::proto::base::avAddress::Clear();
  clear_has_dest();
}
inline const ::proto::base::avAddress& avPacket::dest() const {
  return dest_ != NULL ? *dest_ : *default_instance_->dest_;
}
inline ::proto::base::avAddress* avPacket::mutable_dest() {
  set_has_dest();
  if (dest_ == NULL) dest_ = new ::proto::base::avAddress;
  return dest_;
}
inline ::proto::base::avAddress* avPacket::release_dest() {
  clear_has_dest();
  ::proto::base::avAddress* temp = dest_;
  dest_ = NULL;
  return temp;
}
inline void avPacket::set_allocated_dest(::proto::base::avAddress* dest) {
  delete dest_;
  dest_ = dest;
  if (dest) {
    set_has_dest();
  } else {
    clear_has_dest();
  }
}

// required bytes figurprint = 3;
inline bool avPacket::has_figurprint() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void avPacket::set_has_figurprint() {
  _has_bits_[0] |= 0x00000004u;
}
inline void avPacket::clear_has_figurprint() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void avPacket::clear_figurprint() {
  if (figurprint_ != &::google::protobuf::internal::kEmptyString) {
    figurprint_->clear();
  }
  clear_has_figurprint();
}
inline const ::std::string& avPacket::figurprint() const {
  return *figurprint_;
}
inline void avPacket::set_figurprint(const ::std::string& value) {
  set_has_figurprint();
  if (figurprint_ == &::google::protobuf::internal::kEmptyString) {
    figurprint_ = new ::std::string;
  }
  figurprint_->assign(value);
}
inline void avPacket::set_figurprint(const char* value) {
  set_has_figurprint();
  if (figurprint_ == &::google::protobuf::internal::kEmptyString) {
    figurprint_ = new ::std::string;
  }
  figurprint_->assign(value);
}
inline void avPacket::set_figurprint(const void* value, size_t size) {
  set_has_figurprint();
  if (figurprint_ == &::google::protobuf::internal::kEmptyString) {
    figurprint_ = new ::std::string;
  }
  figurprint_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* avPacket::mutable_figurprint() {
  set_has_figurprint();
  if (figurprint_ == &::google::protobuf::internal::kEmptyString) {
    figurprint_ = new ::std::string;
  }
  return figurprint_;
}
inline ::std::string* avPacket::release_figurprint() {
  clear_has_figurprint();
  if (figurprint_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = figurprint_;
    figurprint_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void avPacket::set_allocated_figurprint(::std::string* figurprint) {
  if (figurprint_ != &::google::protobuf::internal::kEmptyString) {
    delete figurprint_;
  }
  if (figurprint) {
    set_has_figurprint();
    figurprint_ = figurprint;
  } else {
    clear_has_figurprint();
    figurprint_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string upperlayerpotocol = 6 [default = "avim"];
inline bool avPacket::has_upperlayerpotocol() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void avPacket::set_has_upperlayerpotocol() {
  _has_bits_[0] |= 0x00000008u;
}
inline void avPacket::clear_has_upperlayerpotocol() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void avPacket::clear_upperlayerpotocol() {
  if (upperlayerpotocol_ != _default_upperlayerpotocol_) {
    upperlayerpotocol_->assign(*_default_upperlayerpotocol_);
  }
  clear_has_upperlayerpotocol();
}
inline const ::std::string& avPacket::upperlayerpotocol() const {
  return *upperlayerpotocol_;
}
inline void avPacket::set_upperlayerpotocol(const ::std::string& value) {
  set_has_upperlayerpotocol();
  if (upperlayerpotocol_ == _default_upperlayerpotocol_) {
    upperlayerpotocol_ = new ::std::string;
  }
  upperlayerpotocol_->assign(value);
}
inline void avPacket::set_upperlayerpotocol(const char* value) {
  set_has_upperlayerpotocol();
  if (upperlayerpotocol_ == _default_upperlayerpotocol_) {
    upperlayerpotocol_ = new ::std::string;
  }
  upperlayerpotocol_->assign(value);
}
inline void avPacket::set_upperlayerpotocol(const char* value, size_t size) {
  set_has_upperlayerpotocol();
  if (upperlayerpotocol_ == _default_upperlayerpotocol_) {
    upperlayerpotocol_ = new ::std::string;
  }
  upperlayerpotocol_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* avPacket::mutable_upperlayerpotocol() {
  set_has_upperlayerpotocol();
  if (upperlayerpotocol_ == _default_upperlayerpotocol_) {
    upperlayerpotocol_ = new ::std::string(*_default_upperlayerpotocol_);
  }
  return upperlayerpotocol_;
}
inline ::std::string* avPacket::release_upperlayerpotocol() {
  clear_has_upperlayerpotocol();
  if (upperlayerpotocol_ == _default_upperlayerpotocol_) {
    return NULL;
  } else {
    ::std::string* temp = upperlayerpotocol_;
    upperlayerpotocol_ = const_cast< ::std::string*>(_default_upperlayerpotocol_);
    return temp;
  }
}
inline void avPacket::set_allocated_upperlayerpotocol(::std::string* upperlayerpotocol) {
  if (upperlayerpotocol_ != _default_upperlayerpotocol_) {
    delete upperlayerpotocol_;
  }
  if (upperlayerpotocol) {
    set_has_upperlayerpotocol();
    upperlayerpotocol_ = upperlayerpotocol;
  } else {
    clear_has_upperlayerpotocol();
    upperlayerpotocol_ = const_cast< ::std::string*>(_default_upperlayerpotocol_);
  }
}

// optional uint32 encrype_method = 7;
inline bool avPacket::has_encrype_method() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void avPacket::set_has_encrype_method() {
  _has_bits_[0] |= 0x00000010u;
}
inline void avPacket::clear_has_encrype_method() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void avPacket::clear_encrype_method() {
  encrype_method_ = 0u;
  clear_has_encrype_method();
}
inline ::google::protobuf::uint32 avPacket::encrype_method() const {
  return encrype_method_;
}
inline void avPacket::set_encrype_method(::google::protobuf::uint32 value) {
  set_has_encrype_method();
  encrype_method_ = value;
}

// optional bytes payload = 8;
inline bool avPacket::has_payload() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void avPacket::set_has_payload() {
  _has_bits_[0] |= 0x00000020u;
}
inline void avPacket::clear_has_payload() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void avPacket::clear_payload() {
  if (payload_ != &::google::protobuf::internal::kEmptyString) {
    payload_->clear();
  }
  clear_has_payload();
}
inline const ::std::string& avPacket::payload() const {
  return *payload_;
}
inline void avPacket::set_payload(const ::std::string& value) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    payload_ = new ::std::string;
  }
  payload_->assign(value);
}
inline void avPacket::set_payload(const char* value) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    payload_ = new ::std::string;
  }
  payload_->assign(value);
}
inline void avPacket::set_payload(const void* value, size_t size) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    payload_ = new ::std::string;
  }
  payload_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* avPacket::mutable_payload() {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    payload_ = new ::std::string;
  }
  return payload_;
}
inline ::std::string* avPacket::release_payload() {
  clear_has_payload();
  if (payload_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = payload_;
    payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void avPacket::set_allocated_payload(::std::string* payload) {
  if (payload_ != &::google::protobuf::internal::kEmptyString) {
    delete payload_;
  }
  if (payload) {
    set_has_payload();
    payload_ = payload;
  } else {
    clear_has_payload();
    payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// aGMP

// -------------------------------------------------------------------

// avTCPPacket

// required uint32 type = 1;
inline bool avTCPPacket::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void avTCPPacket::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void avTCPPacket::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void avTCPPacket::clear_type() {
  type_ = 0u;
  clear_has_type();
}
inline ::google::protobuf::uint32 avTCPPacket::type() const {
  return type_;
}
inline void avTCPPacket::set_type(::google::protobuf::uint32 value) {
  set_has_type();
  type_ = value;
}

// optional .proto.base.avPacket avpacket = 2;
inline bool avTCPPacket::has_avpacket() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void avTCPPacket::set_has_avpacket() {
  _has_bits_[0] |= 0x00000002u;
}
inline void avTCPPacket::clear_has_avpacket() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void avTCPPacket::clear_avpacket() {
  if (avpacket_ != NULL) avpacket_->::proto::base::avPacket::Clear();
  clear_has_avpacket();
}
inline const ::proto::base::avPacket& avTCPPacket::avpacket() const {
  return avpacket_ != NULL ? *avpacket_ : *default_instance_->avpacket_;
}
inline ::proto::base::avPacket* avTCPPacket::mutable_avpacket() {
  set_has_avpacket();
  if (avpacket_ == NULL) avpacket_ = new ::proto::base::avPacket;
  return avpacket_;
}
inline ::proto::base::avPacket* avTCPPacket::release_avpacket() {
  clear_has_avpacket();
  ::proto::base::avPacket* temp = avpacket_;
  avpacket_ = NULL;
  return temp;
}
inline void avTCPPacket::set_allocated_avpacket(::proto::base::avPacket* avpacket) {
  delete avpacket_;
  avpacket_ = avpacket;
  if (avpacket) {
    set_has_avpacket();
  } else {
    clear_has_avpacket();
  }
}

// optional .proto.base.avAddress endpoint_address = 3;
inline bool avTCPPacket::has_endpoint_address() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void avTCPPacket::set_has_endpoint_address() {
  _has_bits_[0] |= 0x00000004u;
}
inline void avTCPPacket::clear_has_endpoint_address() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void avTCPPacket::clear_endpoint_address() {
  if (endpoint_address_ != NULL) endpoint_address_->::proto::base::avAddress::Clear();
  clear_has_endpoint_address();
}
inline const ::proto::base::avAddress& avTCPPacket::endpoint_address() const {
  return endpoint_address_ != NULL ? *endpoint_address_ : *default_instance_->endpoint_address_;
}
inline ::proto::base::avAddress* avTCPPacket::mutable_endpoint_address() {
  set_has_endpoint_address();
  if (endpoint_address_ == NULL) endpoint_address_ = new ::proto::base::avAddress;
  return endpoint_address_;
}
inline ::proto::base::avAddress* avTCPPacket::release_endpoint_address() {
  clear_has_endpoint_address();
  ::proto::base::avAddress* temp = endpoint_address_;
  endpoint_address_ = NULL;
  return temp;
}
inline void avTCPPacket::set_allocated_endpoint_address(::proto::base::avAddress* endpoint_address) {
  delete endpoint_address_;
  endpoint_address_ = endpoint_address;
  if (endpoint_address) {
    set_has_endpoint_address();
  } else {
    clear_has_endpoint_address();
  }
}

// optional bytes endpoint_cert = 4;
inline bool avTCPPacket::has_endpoint_cert() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void avTCPPacket::set_has_endpoint_cert() {
  _has_bits_[0] |= 0x00000008u;
}
inline void avTCPPacket::clear_has_endpoint_cert() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void avTCPPacket::clear_endpoint_cert() {
  if (endpoint_cert_ != &::google::protobuf::internal::kEmptyString) {
    endpoint_cert_->clear();
  }
  clear_has_endpoint_cert();
}
inline const ::std::string& avTCPPacket::endpoint_cert() const {
  return *endpoint_cert_;
}
inline void avTCPPacket::set_endpoint_cert(const ::std::string& value) {
  set_has_endpoint_cert();
  if (endpoint_cert_ == &::google::protobuf::internal::kEmptyString) {
    endpoint_cert_ = new ::std::string;
  }
  endpoint_cert_->assign(value);
}
inline void avTCPPacket::set_endpoint_cert(const char* value) {
  set_has_endpoint_cert();
  if (endpoint_cert_ == &::google::protobuf::internal::kEmptyString) {
    endpoint_cert_ = new ::std::string;
  }
  endpoint_cert_->assign(value);
}
inline void avTCPPacket::set_endpoint_cert(const void* value, size_t size) {
  set_has_endpoint_cert();
  if (endpoint_cert_ == &::google::protobuf::internal::kEmptyString) {
    endpoint_cert_ = new ::std::string;
  }
  endpoint_cert_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* avTCPPacket::mutable_endpoint_cert() {
  set_has_endpoint_cert();
  if (endpoint_cert_ == &::google::protobuf::internal::kEmptyString) {
    endpoint_cert_ = new ::std::string;
  }
  return endpoint_cert_;
}
inline ::std::string* avTCPPacket::release_endpoint_cert() {
  clear_has_endpoint_cert();
  if (endpoint_cert_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = endpoint_cert_;
    endpoint_cert_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void avTCPPacket::set_allocated_endpoint_cert(::std::string* endpoint_cert) {
  if (endpoint_cert_ != &::google::protobuf::internal::kEmptyString) {
    delete endpoint_cert_;
  }
  if (endpoint_cert) {
    set_has_endpoint_cert();
    endpoint_cert_ = endpoint_cert;
  } else {
    clear_has_endpoint_cert();
    endpoint_cert_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace base
}  // namespace proto

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_avim_2dbase_2eproto__INCLUDED
