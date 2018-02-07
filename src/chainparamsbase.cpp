// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparELPbase.h"

#include "util.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

/**
 * Main network
 */
class CBaseMainParELP : public CBaseChainParELP
{
public:
    CBaseMainParELP()
    {
        networkID = CBaseChainParELP::MAIN;
        nRPCPort = 76101;
    }
};
static CBaseMainParELP mainParELP;

/**
 * Testnet (v3)
 */
class CBaseTestNetParELP : public CBaseMainParELP
{
public:
    CBaseTestNetParELP()
    {
        networkID = CBaseChainParELP::TESTNET;
        nRPCPort = 76201;
        strDataDir = "testnet4";
    }
};
static CBaseTestNetParELP testNetParELP;

/*
 * Regression test
 */
class CBaseRegTestParELP : public CBaseTestNetParELP
{
public:
    CBaseRegTestParELP()
    {
        networkID = CBaseChainParELP::REGTEST;
        strDataDir = "regtest";
    }
};
static CBaseRegTestParELP regTestParELP;

/*
 * Unit test
 */
class CBaseUnitTestParELP : public CBaseMainParELP
{
public:
    CBaseUnitTestParELP()
    {
        networkID = CBaseChainParELP::UNITTEST;
        strDataDir = "unittest";
    }
};
static CBaseUnitTestParELP unitTestParELP;

static CBaseChainParELP* pCurrentBaseParELP = 0;

const CBaseChainParELP& BaseParELP()
{
    assert(pCurrentBaseParELP);
    return *pCurrentBaseParELP;
}

void SelectBaseParELP(CBaseChainParELP::Network network)
{
    switch (network) {
    case CBaseChainParELP::MAIN:
        pCurrentBaseParELP = &mainParELP;
        break;
    case CBaseChainParELP::TESTNET:
        pCurrentBaseParELP = &testNetParELP;
        break;
    case CBaseChainParELP::REGTEST:
        pCurrentBaseParELP = &regTestParELP;
        break;
    case CBaseChainParELP::UNITTEST:
        pCurrentBaseParELP = &unitTestParELP;
        break;
    default:
        assert(false && "Unimplemented network");
        return;
    }
}

CBaseChainParELP::Network NetworkIdFromCommandLine()
{
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest)
        return CBaseChainParELP::MAX_NETWORK_TYPES;
    if (fRegTest)
        return CBaseChainParELP::REGTEST;
    if (fTestNet)
        return CBaseChainParELP::TESTNET;
    return CBaseChainParELP::MAIN;
}

bool SelectBaseParELPFromCommandLine()
{
    CBaseChainParELP::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParELP::MAX_NETWORK_TYPES)
        return false;

    SelectBaseParELP(network);
    return true;
}

bool AreBaseParELPConfigured()
{
    return pCurrentBaseParELP != NULL;
}
