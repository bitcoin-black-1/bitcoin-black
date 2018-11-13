#pragma once

#include <chrono>
#include <cstddef>

namespace rai
{
// Network variants with different genesis blocks and network parameters
enum class bitcoinblack_networks
{
	// Low work parameters, publicly known genesis key, test IP ports
	bitcoinblack_test_network,
	// Normal work parameters, secret beta genesis key, beta IP ports
	bitcoinblack_beta_network,
	// Normal work parameters, secret live key, live IP ports
	bitcoinblack_live_network
};
rai::bitcoinblack_networks const bitcoinblack_network = bitcoinblack_networks::ACTIVE_NETWORK;
std::chrono::milliseconds const transaction_timeout = std::chrono::milliseconds (1000);
}
