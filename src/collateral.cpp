// Copyright (c) 2020 The Odinycoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    CAmount nCollateralRequired;
    
    if (nHeight <= 400) {
        nCollateralRequired = 0 * COIN;
    } else if (nHeight <= 2000) {
        nCollateralRequired = 500 * COIN;
    } else if (nHeight <= 5000) {
        nCollateralRequired = 5000 * COIN;
    } else if (nHeight <= 20000) {
        nCollateralRequired = 10000 * COIN;
    } else if (nHeight <= 40000) {
        nCollateralRequired = 20000 * COIN;
    } else if (nHeight <= 60000) {
        nCollateralRequired = 30000 * COIN;
    } else if (nHeight <= 80000) {
        nCollateralRequired = 40000 * COIN;
    } else if (nHeight <= 100000) {
        nCollateralRequired = 50000 * COIN;
    } else if (nHeight <= 120000) {
        nCollateralRequired = 60000 * COIN;
    } else if (nHeight <= 150000) {
        nCollateralRequired = 70000 * COIN;
    } else if (nHeight <= 170000) {
        nCollateralRequired = 80000 * COIN;
    } else if (nHeight <= 200000) {
        nCollateralRequired = 100000 * COIN;
    } else if (nHeight <= 220000) {
        nCollateralRequired = 150000 * COIN;
    } else if (nHeight <= 240000) {
        nCollateralRequired = 160000 * COIN;
    } else if (nHeight <= 260000) {
        nCollateralRequired = 170000 * COIN;
    } else if (nHeight <= 280000) {
        nCollateralRequired = 180000 * COIN;
    } else if (nHeight <= 300000) {
        nCollateralRequired = 190000 * COIN;
    } else if (nHeight <= 350000) {
        nCollateralRequired = 220000 * COIN;      
    } else if (nHeight <= 400000) {
        nCollateralRequired = 260000 * COIN;                   
    } else {
        nCollateralRequired = 300000 * COIN;
    }

    return nCollateralRequired;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}