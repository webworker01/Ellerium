// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2018 The Ellerium developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include <assert.h>
#include <boost/assign/list_of.hpp>
using namespace std;
using namespace boost::assign;
struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};
#include "chainparamsseeds.h"
/**
 * Main network
 */
//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}
//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions

// 100 000002efcd0a7b5401f8f964da7d59e7e7bc97683f986d1a295e5a73eca82115
// 1000 000000050f6aef7d6f40d0cdf0e0aa7d1c2e61df8baa749690362ea17d0858cc
// 2500 00000001391861008686ef56ad88dc081008fcbf0d3f8b35feaaa8f9f5b1bf38
// 5000 00000006c99fde6e870ace24f99cebc6f8515df5afb06fe8a086a4f12962e674
// 10000 0000000104ef393983220a2eec841527ff61cd04ad3b98cfbf83f6ebdfd2dd33
// 25000 0000000099d13ab3e0210d072a7ab394c1ec3e8a2efe9c3835fa5c3f36d5623c
// 50000 000000034bdb1897922d0dd2608ccd71ec3782a021ddb619c3366195e3210b4c
// 75000 000000008f1aa425f16d3858160f3f9db4d8df7f471b8b243d493a075de28e53
// 100000 000000001a2a84195221e3f9a0ffecbd80b7f8c308c8144f5781dbcdbb3ce3ce
// 125000 0000000164a51694ebddfc2d653625e77f30344c3f5618f0b79a773b5fa14c04
// 140000 00000000ce15c109cd977c89cac631932b9706ffa3236ae71ccf755281d74163
// 145000 00000000978ef8e749fbb77b6d8be5d8e92f6e78192752adee6d4734888a9e27
// 163813 00000000fbaeeb07c4355c4c2f90548991189e89c2928e6048def02e226ffead

static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
	(0, uint256("0x0000016c5074e3a3d7df0c9b9cdc38ef6a72be36c4a3a0233a564533120957f5"))
	(2, uint256("0x00000bfa9f5517a83532d103038e78941ed28eda11b8fa920cc6c1659e569f75"))
	(100, uint256("0x000002efcd0a7b5401f8f964da7d59e7e7bc97683f986d1a295e5a73eca82115"))
	(1000, uint256("0x000000050f6aef7d6f40d0cdf0e0aa7d1c2e61df8baa749690362ea17d0858cc"))
	(2500, uint256("0x00000001391861008686ef56ad88dc081008fcbf0d3f8b35feaaa8f9f5b1bf38"))
	(5000, uint256("0x00000006c99fde6e870ace24f99cebc6f8515df5afb06fe8a086a4f12962e674"))
	(10000, uint256("0x0000000104ef393983220a2eec841527ff61cd04ad3b98cfbf83f6ebdfd2dd33"))
	(25000, uint256("0x0000000099d13ab3e0210d072a7ab394c1ec3e8a2efe9c3835fa5c3f36d5623c"))
	(50000, uint256("0x000000034bdb1897922d0dd2608ccd71ec3782a021ddb619c3366195e3210b4c"))
	(67260, uint256("0x0000000009e85f5c57095d56743bc79f347d36ebf1e142b17ba47f4f2c587b6e"))
	(75000, uint256("0x000000008f1aa425f16d3858160f3f9db4d8df7f471b8b243d493a075de28e53"))
	(100000, uint256("0x000000001a2a84195221e3f9a0ffecbd80b7f8c308c8144f5781dbcdbb3ce3ce"))
	(125000, uint256("0x0000000164a51694ebddfc2d653625e77f30344c3f5618f0b79a773b5fa14c04"))
	(140000, uint256("0x00000000ce15c109cd977c89cac631932b9706ffa3236ae71ccf755281d74163"))
	(145000, uint256("0x00000000978ef8e749fbb77b6d8be5d8e92f6e78192752adee6d4734888a9e27"))
	(163813, uint256("0x00000000fbaeeb07c4355c4c2f90548991189e89c2928e6048def02e226ffead"));
    
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1512554966, // * UNIX timestamp of last checkpoint block
    295000,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1454124731,
    0,
    250};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x00;
        pchMessageStart[1] = 0x22;
        pchMessageStart[2] = 0x00;
        pchMessageStart[3] = 0xaa;
        vAlertPubKey = ParseHex("04d6d976efad463fa258e3699e9c3fea60d5168a065abb5829a77448d25e0acbee58bb8f5be56491624b9a48611a8c456a592d45f48ea9c9f0bdc30904534be285");
        nDefaultPort = 50020;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Ellerium starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Ellerium: 1 minute
        nTargetSpacing = 1 * 60;  // Ellerium: 1 minute
        nLastPOWBlock = 259200;
        nMaturity = 101;
        nModifierUpdateBlock = 1;
        const char* pszTimestamp = "Ellerium 22-07-2017";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("0421fb0665876637d9d79d03a24f383393838fb9e3340858a6d5a70b079f4af57cfff3ca00310be5300d532adf6261ba98ac70d24d943a6be333bec6d7a6d93013") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1500685200;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 1402465;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000016c5074e3a3d7df0c9b9cdc38ef6a72be36c4a3a0233a564533120957f5"));
        assert(genesis.hashMerkleRoot == uint256("0xcdf9a0f882351aa571e3f647ef82858c08b5eb4f1847df68787f15cc42c36529"));
		
        vSeeds.push_back(CDNSSeedData("nl-1.ellerium.com", "nl-1.ellerium.com"));
        vSeeds.push_back(CDNSSeedData("us-1.ellerium.com", "us-1.ellerium.com"));
		vSeeds.push_back(CDNSSeedData("us-2.ellerium.com", "us-2.ellerium.com"));
		vSeeds.push_back(CDNSSeedData("eu-1.ellerium.com", "eu-1.ellerium.com"));
		vSeeds.push_back(CDNSSeedData("eu-2.ellerium.com", "eu-2.ellerium.com"));
		vSeeds.push_back(CDNSSeedData("asia-1.ellerium.com", "asia-1.ellerium.com"));
		
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 23);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        //  BIP44 coin type is 'TBD'
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x13)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;
        nPoolMaxTransactions = 3;
        strSporkKey = "04d6d976efad463fa258e3699e9c3fea60d5168a065abb5829a77448d25e0acbee58bb8f5be56491624b9a48611a8c456a592d45f48ea9c9f0bdc30904534be285";
        
        strObfuscationPoolDummyAddress = "AWSbBnzmNkjDVaYHX7vkL1MqD96pRYWtZo";
        nStartMasternodePayments = 1403728576; //Wed, 25 Jun 2014 20:36:16 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("000010e83b2703ccf322f7dbd62dd5855ac7c10bd055814ce121ba32607d573b8810c02c0582aed05b4deb9c4b77b26d92428c61256cd42774babea0a073b2ed0c9");
        nDefaultPort = 51474;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Ellerium: 1 day
        nTargetSpacing = 1 * 60;  // Ellerium: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1454124731;
        genesis.nNonce = 2402015;
        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));
        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "ellerium-testnet.seed.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "ellerium-testnet.seed2.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("s3v3nh4cks.ddns.net", "s3v3nh4cks.ddns.net"));
        vSeeds.push_back(CDNSSeedData("88.198.192.110", "88.198.192.110"));
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet ellerium addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet ellerium script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet ellerium BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet ellerium BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet ellerium BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x01)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
        nPoolMaxTransactions = 2;
        strSporkKey = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Ellerium: 1 day
        nTargetSpacing = 1 * 60;        // Ellerium: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1454124731;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;
        //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));
        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }
    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;
static CChainParams* pCurrentParams = 0;
CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}
const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}
CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}
void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;
    SelectParams(network);
    return true;
}