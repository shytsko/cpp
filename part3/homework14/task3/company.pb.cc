// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: company.proto
// Protobuf C++ Version: 5.26.1

#include "company.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr Company::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        address_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        scopeactivity_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        foreigneconomicactivity_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        foundingyear_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Company::Company(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct CompanyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CompanyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CompanyDefaultTypeInternal() {}
  union {
    Company _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CompanyDefaultTypeInternal _Company_default_instance_;
static ::_pb::Metadata file_level_metadata_company_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_company_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_company_2eproto = nullptr;
const ::uint32_t
    TableStruct_company_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::Company, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::Company, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Company, _impl_.foundingyear_),
        PROTOBUF_FIELD_OFFSET(::Company, _impl_.name_),
        PROTOBUF_FIELD_OFFSET(::Company, _impl_.address_),
        PROTOBUF_FIELD_OFFSET(::Company, _impl_.scopeactivity_),
        PROTOBUF_FIELD_OFFSET(::Company, _impl_.foreigneconomicactivity_),
        4,
        0,
        1,
        2,
        3,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 13, -1, sizeof(::Company)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_Company_default_instance_._instance,
};
const char descriptor_table_protodef_company_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\rcompany.proto\"v\n\007Company\022\024\n\014foundingYe"
    "ar\030\001 \002(\005\022\014\n\004name\030\002 \002(\t\022\017\n\007address\030\003 \002(\t\022"
    "\025\n\rscopeActivity\030\004 \001(\t\022\037\n\027foreignEconomi"
    "cActivity\030\005 \001(\t"
};
static ::absl::once_flag descriptor_table_company_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_company_2eproto = {
    false,
    false,
    135,
    descriptor_table_protodef_company_2eproto,
    "company.proto",
    &descriptor_table_company_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_company_2eproto::offsets,
    file_level_metadata_company_2eproto,
    file_level_enum_descriptors_company_2eproto,
    file_level_service_descriptors_company_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_company_2eproto_getter() {
  return &descriptor_table_company_2eproto;
}
// ===================================================================

class Company::_Internal {
 public:
  using HasBits = decltype(std::declval<Company>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(Company, _impl_._has_bits_);
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000013) ^ 0x00000013) != 0;
  }
};

Company::Company(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Company)
}
inline PROTOBUF_NDEBUG_INLINE Company::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        name_(arena, from.name_),
        address_(arena, from.address_),
        scopeactivity_(arena, from.scopeactivity_),
        foreigneconomicactivity_(arena, from.foreigneconomicactivity_) {}

Company::Company(
    ::google::protobuf::Arena* arena,
    const Company& from)
    : ::google::protobuf::Message(arena) {
  Company* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  _impl_.foundingyear_ = from._impl_.foundingyear_;

  // @@protoc_insertion_point(copy_constructor:Company)
}
inline PROTOBUF_NDEBUG_INLINE Company::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        name_(arena),
        address_(arena),
        scopeactivity_(arena),
        foreigneconomicactivity_(arena) {}

inline void Company::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.foundingyear_ = {};
}
Company::~Company() {
  // @@protoc_insertion_point(destructor:Company)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Company::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.name_.Destroy();
  _impl_.address_.Destroy();
  _impl_.scopeactivity_.Destroy();
  _impl_.foreigneconomicactivity_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Company::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(Company, _impl_._cached_size_),
              false,
          },
          &Company::MergeImpl,
          &Company::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void Company::Clear() {
// @@protoc_insertion_point(message_clear_start:Company)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x0000000fu) {
    if (cached_has_bits & 0x00000001u) {
      _impl_.name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      _impl_.address_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      _impl_.scopeactivity_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000008u) {
      _impl_.foreigneconomicactivity_.ClearNonDefaultToEmpty();
    }
  }
  _impl_.foundingyear_ = 0;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Company::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 5, 0, 63, 2> Company::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Company, _impl_._has_bits_),
    0, // no _extensions_
    5, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967264,  // skipmap
    offsetof(decltype(_table_), field_entries),
    5,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Company_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Company>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // required int32 foundingYear = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Company, _impl_.foundingyear_), 4>(),
     {8, 4, 0, PROTOBUF_FIELD_OFFSET(Company, _impl_.foundingyear_)}},
    // required string name = 2;
    {::_pbi::TcParser::FastSS1,
     {18, 0, 0, PROTOBUF_FIELD_OFFSET(Company, _impl_.name_)}},
    // required string address = 3;
    {::_pbi::TcParser::FastSS1,
     {26, 1, 0, PROTOBUF_FIELD_OFFSET(Company, _impl_.address_)}},
    // optional string scopeActivity = 4;
    {::_pbi::TcParser::FastSS1,
     {34, 2, 0, PROTOBUF_FIELD_OFFSET(Company, _impl_.scopeactivity_)}},
    // optional string foreignEconomicActivity = 5;
    {::_pbi::TcParser::FastSS1,
     {42, 3, 0, PROTOBUF_FIELD_OFFSET(Company, _impl_.foreigneconomicactivity_)}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // required int32 foundingYear = 1;
    {PROTOBUF_FIELD_OFFSET(Company, _impl_.foundingyear_), _Internal::kHasBitsOffset + 4, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // required string name = 2;
    {PROTOBUF_FIELD_OFFSET(Company, _impl_.name_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // required string address = 3;
    {PROTOBUF_FIELD_OFFSET(Company, _impl_.address_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional string scopeActivity = 4;
    {PROTOBUF_FIELD_OFFSET(Company, _impl_.scopeactivity_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
    // optional string foreignEconomicActivity = 5;
    {PROTOBUF_FIELD_OFFSET(Company, _impl_.foreigneconomicactivity_), _Internal::kHasBitsOffset + 3, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kRawString | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\7\0\4\7\15\27\0\0"
    "Company"
    "name"
    "address"
    "scopeActivity"
    "foreignEconomicActivity"
  }},
};

::uint8_t* Company::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Company)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // required int32 foundingYear = 1;
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<1>(
            stream, this->_internal_foundingyear(), target);
  }

  // required string name = 2;
  if (cached_has_bits & 0x00000001u) {
    const std::string& _s = this->_internal_name();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "Company.name");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  // required string address = 3;
  if (cached_has_bits & 0x00000002u) {
    const std::string& _s = this->_internal_address();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "Company.address");
    target = stream->WriteStringMaybeAliased(3, _s, target);
  }

  // optional string scopeActivity = 4;
  if (cached_has_bits & 0x00000004u) {
    const std::string& _s = this->_internal_scopeactivity();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "Company.scopeActivity");
    target = stream->WriteStringMaybeAliased(4, _s, target);
  }

  // optional string foreignEconomicActivity = 5;
  if (cached_has_bits & 0x00000008u) {
    const std::string& _s = this->_internal_foreigneconomicactivity();
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(_s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormat::SERIALIZE,
                                "Company.foreignEconomicActivity");
    target = stream->WriteStringMaybeAliased(5, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Company)
  return target;
}

::size_t Company::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Company)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // required string name = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_name());
    }

    // required string address = 3;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_address());
    }

  }
  if (cached_has_bits & 0x0000000cu) {
    // optional string scopeActivity = 4;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_scopeactivity());
    }

    // optional string foreignEconomicActivity = 5;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                      this->_internal_foreigneconomicactivity());
    }

  }
  // required int32 foundingYear = 1;
  if (cached_has_bits & 0x00000010u) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_foundingyear());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Company::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Company*>(&to_msg);
  auto& from = static_cast<const Company&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Company)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_name(from._internal_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_set_address(from._internal_address());
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_internal_set_scopeactivity(from._internal_scopeactivity());
    }
    if (cached_has_bits & 0x00000008u) {
      _this->_internal_set_foreigneconomicactivity(from._internal_foreigneconomicactivity());
    }
    if (cached_has_bits & 0x00000010u) {
      _this->_impl_.foundingyear_ = from._impl_.foundingyear_;
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Company::CopyFrom(const Company& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Company)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Company::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_impl_._has_bits_)) {
    return false;
  }
  return true;
}

void Company::InternalSwap(Company* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.name_, &other->_impl_.name_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.address_, &other->_impl_.address_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.scopeactivity_, &other->_impl_.scopeactivity_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.foreigneconomicactivity_, &other->_impl_.foreigneconomicactivity_, arena);
        swap(_impl_.foundingyear_, other->_impl_.foundingyear_);
}

::google::protobuf::Metadata Company::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_company_2eproto_getter,
                                   &descriptor_table_company_2eproto_once,
                                   file_level_metadata_company_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_company_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"