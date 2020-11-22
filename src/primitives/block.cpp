// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/block.h"

#include "hash.h"
#include "streams.h"
#include "tinyformat.h"
#include "utilstrencodings.h"
#include "crypto/common.h"

uint256 CBlockHeader::GetHash() const
{
	std::vector<unsigned char> vch(80);
	CVectorWriter ss(SER_NETWORK, 70216, vch, 0);
	ss << *this;
	    
    if(nHeight < 53875 ) {
    	return HashX11((const char *)vch.data(), (const char *)vch.data() + vch.size());
    }
    else {
    	return KAWPOWHash_OnlyMix(*this);
    }
}

uint256 CBlockHeader::GetHashFull(uint256& mix_hash) const
{
	std::vector<unsigned char> vch(80);
	CVectorWriter ss(SER_NETWORK, 70216, vch, 0);
	ss << *this;
    
    if (nHeight < 53875) {
        return HashX11((const char *)vch.data(), (const char *)vch.data() + vch.size());
    } else {
        return KAWPOWHash(*this, mix_hash);
    }
}

uint256 CBlockHeader::GetKAWPOWHeaderHash() const
{
    CKAWPOWInput input{*this};

    return SerializeHash(input);
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, nNonce64=%u, vtx=%u)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,nNonce64,
        vtx.size());
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
