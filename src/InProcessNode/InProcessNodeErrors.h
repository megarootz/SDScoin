// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
// Copyright (c) 2018-2019 xDrop developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>
#include <system_error>

namespace CryptoNote {
namespace error {

enum InProcessNodeErrorCodes {
  NOT_INITIALIZED = 1,
  ALREADY_INITIALIZED,
  NETWORK_ERROR,
  NODE_BUSY,
  INTERNAL_NODE_ERROR,
  REQUEST_ERROR,
  HANDLE_INCOMING_TX_ERROR,
  TX_VERIFICATION_FAILED,
  SHOULD_BE_RELAYED,
  TX_OUTPUTS,
  RND_OUTS,
  MISSED_TX,
  POOL_TX_BY_TIMESTAMP,
  TX_BY_PAYMENTID,
  NO_KNOWN_BLOCKID,
  BLOCKID_IS_NOT_GENESIS,
  HEIGHT_TOO_BIG,
  NO_BLOCK_BY_HASH,
  NO_BLOCK_BY_TIMESTAMP
};

class InProcessNodeErrorCategory : public std::error_category {
public:
  static InProcessNodeErrorCategory INSTANCE;

  virtual const char* name() const throw() override {
    return "InProcessNodeErrorCategory";
  }

  virtual std::error_condition default_error_condition(int ev) const throw() override {
    return std::error_condition(ev, *this);
  }

  virtual std::string message(int ev) const override {
    switch (ev) {
      case NOT_INITIALIZED:               return "Object was not initialized";
      case ALREADY_INITIALIZED:           return "Object has been already initialized";
      case NETWORK_ERROR:                 return "Network error";
      case NODE_BUSY:                     return "Node is busy";
      case INTERNAL_NODE_ERROR:           return "Internal node error";
      case REQUEST_ERROR:                 return "Error in request parameters";
      case HANDLE_INCOMING_TX_ERROR:      return "Could not handle incoming transaction";
      case TX_VERIFICATION_FAILED:        return "Could not verify transaction";
      case SHOULD_BE_RELAYED:             return "Should be relayed";
      case TX_OUTPUTS:                    return "Could not get transaction outputs";
      case RND_OUTS:                      return "Could not get random outputs";
      case MISSED_TX:                     return "There was a missed transaction";
      case POOL_TX_BY_TIMESTAMP:          return "Could not get transaction pool by timestamp";
      case TX_BY_PAYMENTID:               return "Couldn't find transaction under that Payment ID";
      case NO_KNOWN_BLOCKID:              return "No known block IDs";
      case BLOCKID_IS_NOT_GENESIS:        return "First block is not genesis";
      case HEIGHT_TOO_BIG:                return "Height cannot be larger than top height";
      case NO_BLOCK_BY_HASH:              return "Could not get block by hash";
      case NO_BLOCK_BY_TIMESTAMP:         return "Could not get block by timestamp";
      default:                            return "Unknown error";
    }
  }

private:
  InProcessNodeErrorCategory() {
  }
};

} //namespace error
} //namespace CryptoNote

inline std::error_code make_error_code(CryptoNote::error::InProcessNodeErrorCodes e) {
  return std::error_code(static_cast<int>(e), CryptoNote::error::InProcessNodeErrorCategory::INSTANCE);
}
