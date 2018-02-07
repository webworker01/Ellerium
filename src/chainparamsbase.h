// Copyright (c) 2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CHAINPARELPBASE_H
#define BITCOIN_CHAINPARELPBASE_H

#include <string>
#include <vector>

/**
 * CBaseChainParELP defines the base parameters (shared between ellerium-cli and elleriumd)
 * of a given instance of the Ellerium system.
 */
class CBaseChainParELP
{
public:
    enum Network {
        MAIN,
        TESTNET,
        REGTEST,
        UNITTEST,

        MAX_NETWORK_TYPES
    };

    const std::string& DataDir() const { return strDataDir; }
    int RPCPort() const { return nRPCPort; }

protected:
    CBaseChainParELP() {}

    int nRPCPort;
    std::string strDataDir;
    Network networkID;
};

/**
 * Return the currently selected parameters. This won't change after app startup
 * outside of the unit tests.
 */
const CBaseChainParELP& BaseParELP();

/** Sets the parELP returned by ParELP() to those for the given network. */
void SelectBaseParELP(CBaseChainParELP::Network network);

/**
 * Looks for -regtest or -testnet and returns the appropriate Network ID.
 * Returns MAX_NETWORK_TYPES if an invalid combination is given.
 */
CBaseChainParELP::Network NetworkIdFromCommandLine();

/**
 * Calls NetworkIdFromCommandLine() and then calls SelectParELP as appropriate.
 * Returns false if an invalid combination is given.
 */
bool SelectBaseParELPFromCommandLine();

/**
 * Return true if SelectBaseParELPFromCommandLine() has been called to select
 * a network.
 */
bool AreBaseParELPConfigured();

#endif // BITCOIN_CHAINPARELPBASE_H
