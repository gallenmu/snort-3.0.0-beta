//--------------------------------------------------------------------------
// Copyright (C) 2014-2018 Cisco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------
// codec_module.h author Russ Combs <rucombs@cisco.com>
// codec_module.h author Josh Rosenbaum <jrosenba@cisco.com>

#ifndef CODECS_CODEC_MODULE_H
#define CODECS_CODEC_MODULE_H

#include <cstdint>

#include "framework/module.h"
#include "main/snort_debug.h"
#include "main/snort_types.h"

namespace snort
{
constexpr int GID_DECODE = 116;

//-----------------------------------------------------
// remember to add rules to preproc_rules/decoder.rules
// add the new decoder rules to the following enum.

enum CodecSid : uint32_t
{
    DECODE_NOT_IPV4_DGRAM = 1,
    DECODE_IPV4_INVALID_HEADER_LEN = 2,
    DECODE_IPV4_DGRAM_LT_IPHDR = 3,
    DECODE_IPV4OPT_BADLEN = 4,
    DECODE_IPV4OPT_TRUNCATED = 5,
    DECODE_IPV4_DGRAM_GT_CAPLEN = 6,

    DECODE_TCP_DGRAM_LT_TCPHDR = 45,
    DECODE_TCP_INVALID_OFFSET = 46,
    DECODE_TCP_LARGE_OFFSET = 47,

    DECODE_TCPOPT_BADLEN = 54,
    DECODE_TCPOPT_TRUNCATED = 55,
    DECODE_TCPOPT_TTCP = 56,
    DECODE_TCPOPT_OBSOLETE = 57,
    DECODE_TCPOPT_EXPERIMENTAL = 58,
    DECODE_TCPOPT_WSCALE_INVALID = 59,

    DECODE_UDP_DGRAM_LT_UDPHDR = 95,
    DECODE_UDP_DGRAM_INVALID_LENGTH = 96,
    DECODE_UDP_DGRAM_SHORT_PACKET = 97,
    DECODE_UDP_DGRAM_LONG_PACKET = 98,

    DECODE_ICMP_DGRAM_LT_ICMPHDR = 105,
    DECODE_ICMP_DGRAM_LT_TIMESTAMPHDR = 106,
    DECODE_ICMP_DGRAM_LT_ADDRHDR = 107,

    DECODE_ARP_TRUNCATED = 109,
    DECODE_EAPOL_TRUNCATED = 110,
    DECODE_EAPKEY_TRUNCATED = 111,
    DECODE_EAP_TRUNCATED = 112,

    DECODE_BAD_PPPOE = 120,
    DECODE_BAD_VLAN = 130,
    DECODE_BAD_LLC_HEADER = 131,
    DECODE_BAD_LLC_OTHER = 132,
    DECODE_BAD_80211_ETHLLC = 133,
    DECODE_BAD_80211_OTHER = 134,

    DECODE_BAD_TRH = 140,
    DECODE_BAD_TR_ETHLLC = 141,
    DECODE_BAD_TR_MR_LEN = 142,
    DECODE_BAD_TRHMR = 143,

    DECODE_BAD_TRAFFIC_LOOPBACK = 150,
    DECODE_BAD_TRAFFIC_SAME_SRCDST = 151,

    DECODE_GRE_DGRAM_LT_GREHDR = 160,
    DECODE_GRE_MULTIPLE_ENCAPSULATION = 161,
    DECODE_GRE_INVALID_VERSION = 162,
    DECODE_GRE_INVALID_HEADER = 163,
    DECODE_GRE_V1_INVALID_HEADER = 164,
    DECODE_GRE_TRANS_DGRAM_LT_TRANSHDR = 165,

    DECODE_BAD_MPLS = 170,
    DECODE_BAD_MPLS_LABEL0 = 171,
    DECODE_BAD_MPLS_LABEL1 = 172,
    DECODE_BAD_MPLS_LABEL2 = 173,
    DECODE_BAD_MPLS_LABEL3 = 174,
    DECODE_MPLS_RESERVED_LABEL = 175,
    DECODE_MPLS_LABEL_STACK = 176,

    DECODE_ICMP_ORIG_IP_TRUNCATED = 250,
    DECODE_ICMP_ORIG_IP_VER_MISMATCH = 251,
    DECODE_ICMP_ORIG_DGRAM_LT_ORIG_IP = 252,
    DECODE_ICMP_ORIG_PAYLOAD_LT_64 = 253,
    DECODE_ICMP_ORIG_PAYLOAD_GT_576 = 254,
    DECODE_ICMP_ORIG_IP_WITH_FRAGOFFSET = 255,

    DECODE_IPV6_MIN_TTL = 270,
    DECODE_IPV6_IS_NOT = 271,
    DECODE_IPV6_TRUNCATED_EXT = 272,
    DECODE_IPV6_TRUNCATED = 273,
    DECODE_IPV6_DGRAM_LT_IPHDR = 274,
    DECODE_IPV6_DGRAM_GT_CAPLEN = 275,
    DECODE_IPV6_DST_ZERO = 276,
    DECODE_IPV6_SRC_MULTICAST = 277,
    DECODE_IPV6_DST_RESERVED_MULTICAST = 278,
    DECODE_IPV6_BAD_OPT_TYPE = 279,
    DECODE_IPV6_BAD_MULTICAST_SCOPE = 280,
    DECODE_IPV6_BAD_NEXT_HEADER = 281,
    DECODE_IPV6_ROUTE_AND_HOPBYHOP = 282,
    DECODE_IPV6_TWO_ROUTE_HEADERS = 283,

    DECODE_ICMPV6_TOO_BIG_BAD_MTU = 285,
    DECODE_ICMPV6_UNREACHABLE_NON_RFC_2463_CODE = 286,
    DECODE_ICMPV6_SOLICITATION_BAD_CODE = 287,
    DECODE_ICMPV6_ADVERT_BAD_CODE = 288,
    DECODE_ICMPV6_SOLICITATION_BAD_RESERVED = 289,
    DECODE_ICMPV6_ADVERT_BAD_REACHABLE = 290,

    DECODE_IPV6_TUNNELED_IPV4_TRUNCATED = 291,
    DECODE_IPV6_DSTOPTS_WITH_ROUTING = 292,
    DECODE_IP_MULTIPLE_ENCAPSULATION = 293,

    DECODE_ESP_HEADER_TRUNC = 294,
    DECODE_IPV6_BAD_OPT_LEN = 295,
    DECODE_IPV6_UNORDERED_EXTENSIONS = 296,

    DECODE_GTP_MULTIPLE_ENCAPSULATION = 297,
    DECODE_GTP_BAD_LEN = 298,

    DECODE_TCP_XMAS = 400,
    DECODE_TCP_NMAP_XMAS,
    DECODE_DOS_NAPTHA,
    DECODE_SYN_TO_MULTICAST,
    DECODE_ZERO_TTL,
    DECODE_BAD_FRAGBITS,
    DECODE_UDP_IPV6_ZERO_CHECKSUM,
    DECODE_IP4_LEN_OFFSET,
    DECODE_IP4_SRC_THIS_NET,
    DECODE_IP4_DST_THIS_NET,
    DECODE_IP4_SRC_MULTICAST,
    DECODE_IP4_SRC_RESERVED,
    DECODE_IP4_DST_RESERVED,
    DECODE_IP4_SRC_BROADCAST,
    DECODE_IP4_DST_BROADCAST,
    DECODE_ICMP4_DST_MULTICAST,
    DECODE_ICMP4_DST_BROADCAST,
    DECODE_ICMP4_TYPE_OTHER = 418,
    DECODE_TCP_BAD_URP,
    DECODE_TCP_SYN_FIN,
    DECODE_TCP_SYN_RST,
    DECODE_TCP_MUST_ACK,
    DECODE_TCP_NO_SYN_ACK_RST,
    DECODE_ETH_HDR_TRUNC,
    DECODE_IP4_HDR_TRUNC,
    DECODE_ICMP4_HDR_TRUNC,
    DECODE_ICMP6_HDR_TRUNC,
    DECODE_IP4_MIN_TTL,
    DECODE_IP6_ZERO_HOP_LIMIT,
    DECODE_IP4_DF_OFFSET, // = 430
    DECODE_ICMP6_TYPE_OTHER,
    DECODE_ICMP6_DST_MULTICAST,
    DECODE_TCP_SHAFT_SYNFLOOD,
    DECODE_ICMP_PING_NMAP,
    DECODE_ICMP_ICMPENUM,
    DECODE_ICMP_REDIRECT_HOST,
    DECODE_ICMP_REDIRECT_NET,
    DECODE_ICMP_TRACEROUTE_IPOPTS,
    DECODE_ICMP_SOURCE_QUENCH,
    DECODE_ICMP_BROADSCAN_SMURF_SCANNER, // = 440
    DECODE_ICMP_DST_UNREACH_ADMIN_PROHIBITED,
    DECODE_ICMP_DST_UNREACH_DST_HOST_PROHIBITED,
    DECODE_ICMP_DST_UNREACH_DST_NET_PROHIBITED,
    DECODE_IP_OPTION_SET,
    DECODE_UDP_LARGE_PACKET,
    DECODE_TCP_PORT_ZERO,
    DECODE_UDP_PORT_ZERO,
    DECODE_IP_RESERVED_FRAG_BIT,
    DECODE_IP_UNASSIGNED_PROTO,
    DECODE_IP_BAD_PROTO, // = 450
    DECODE_ICMP_PATH_MTU_DOS,
    DECODE_ICMP_DOS_ATTEMPT,
    DECODE_IPV6_ISATAP_SPOOF,
    DECODE_PGM_NAK_OVERFLOW,
    DECODE_IGMP_OPTIONS_DOS,
    DECODE_IP6_EXCESS_EXT_HDR,
    DECODE_ICMPV6_UNREACHABLE_NON_RFC_4443_CODE,
    DECODE_IPV6_BAD_FRAG_PKT,
    DECODE_ZERO_LENGTH_FRAG,
    DECODE_ICMPV6_NODE_INFO_BAD_CODE, // = 460
    DECODE_IPV6_ROUTE_ZERO,
    DECODE_ERSPAN_HDR_VERSION_MISMATCH,
    DECODE_ERSPAN2_DGRAM_LT_HDR,
    DECODE_ERSPAN3_DGRAM_LT_HDR,
    DECODE_AUTH_HDR_TRUNC,
    DECODE_AUTH_HDR_BAD_LEN,
    DECODE_FPATH_HDR_TRUNC,
    DECODE_CISCO_META_HDR_TRUNC,
    DECODE_CISCO_META_HDR_OPT_LEN,
    DECODE_CISCO_META_HDR_OPT_TYPE, // = 470
    DECODE_CISCO_META_HDR_SGT,
    DECODE_TOO_MANY_LAYERS,
    DECODE_BAD_ETHER_TYPE,
    DECODE_ICMP6_NOT_IP6,
    DECODE_MIPV6_BAD_PAYLOAD_PROTO,
    DECODE_INDEX_MAX
};

//-------------------------------------------------------------------------
// module
//-------------------------------------------------------------------------

class SO_PUBLIC CodecModule : public Module
{
public:
    CodecModule();
    CodecModule(const char* s, const char* h) : Module(s, h)
    { }

    CodecModule(const char* s, const char* h, const Parameter* p, bool is_list = false)
        : Module(s, h, p, is_list) { }

    unsigned get_gid() const override
    { return GID_DECODE; }

    const RuleMap* get_rules() const override;

    Usage get_usage() const override
    { return CONTEXT; }

    bool set(const char*, snort::Value&, snort::SnortConfig*) override;
};
}

extern Trace TRACE_NAME(decode);

#endif

