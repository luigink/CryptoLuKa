// Copyright (c) 2018, CryptoLuKa developers
// Copyright (c) 2017, Intense Coin developers
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 90; // seconds
const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;//INT
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 5000000000;//BYTES
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;//BYTES
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x17eda7e1; // numero hex del prefijo deseado denuestra moneda emetb
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10; //transacciones a esperar para pagar una transaccion minimo 6
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 270; // DIFFICULTY_TARGET * (DIFFICULTY_WINDOW_V4 - 1) / 20 bloques futuros a la espera....

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V4          = 11;

// MONEY_SUPPLY - total number coins to be generated
// desde aca se cambian los registros de nuestras monedas
const uint64_t MONEY_SUPPLY					= UINT64_C(10000000000000000); // 100M //maximo de monedas a generar
const uint64_t FINAL_SUBSIDY_PER_MINUTE				= UINT64_C(20000000); // 0.20 LUK // pago luego del max de monedas
const unsigned EMISSION_SPEED_FACTOR                        	= 22;//ultimo factor para la emision de recompensas pendientes
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               	= 100;//ventana minima de bloques...
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     	= 1000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  	= 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  	= 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;

const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600; //PESO EN BYTES EN LAS TRANSACCIONES MAXIMO, SI TIENE MAS DE 600 SON INVALIDAS
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;//maximo de decimales
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);    // pow(10, 5) //fee minimo para comision por defecto 1m
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);    // pow(10, 5) // si el de arriba falla, el segundo se queda con ella

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET; // numero esperado de bloques por dia
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15; //ya no se utiliza.... remplazado por deifculty block window
//v1 algoritmo inicial, v2 un poco mas robusta, v3 el nivel con mas "validaciones"
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t  DIFFICULTY_BLOCKS_V2							 = 17;
const size_t  DIFFICULTY_CUT_V2								 = 6;
const size_t  DIFFICULTY_WINDOW_V2							 = DIFFICULTY_BLOCKS_V2 + DIFFICULTY_CUT_V2 * 2;
const size_t  DIFFICULTY_WINDOW_V4							 = 61;

//tamaños finales de los bloques
const size_t   MAX_BLOCK_SIZE_INITIAL                        	= 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         	= 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR_V2		= 35 * 100 * 1024;
const size_t   MAX_BLOCK_SIZE_ALLOWED_EVERY_N_BLOCK		= 5;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       	= 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     	= 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    	= DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

//mempool. todas las transacciones que realizamos...
const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                	= 60 * 60 * 24;     //seconds, one day //sino se confirma en 1 dia se anula
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME 	= 60 * 60 * 24 * 7; //seconds, one week //cadena alternativa a la anterior
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7; //dias...  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 15 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

//todo lo relacionado a index. significa mas validacion,
//keyimage  max tamaño de indice se duplica
const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 0; //recomendacion, inicializar en 0 estaba en 2000000
const uint32_t UPGRADE_HEIGHT_V2                             = 1;
const uint32_t UPGRADE_HEIGHT_MAX_BLOCK_SIZE                 = 2;
const uint32_t UPGRADE_HEIGHT_V3                             = 3;
const uint32_t UPGRADE_HEIGHT_V4                             = 4;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks

static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  	= "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            	= "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                	= "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       	= "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      	= "miner_conf.json";
} // parameters


const char     CRYPTONOTE_NAME[]                             = "MrCoin";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  7946;//puertos personalizados inicial: 52420
const int      RPC_DEFAULT_PORT                              =  4613;//puertos personalizados inicial: 52421 pero son iguales

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8; //no poner menos de 8 por default
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds para consultar si tengo todos los peers
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds

const char     P2P_STAT_TRUSTED_PUB_KEY[] = "";

const char* const SEED_NODES[] = {
	"192.168.0.126:7946",
	"192.168.0.102:7946"
};

struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const CheckpointData CHECKPOINTS[] = {
	{ 9000, "3e7b089856003ff9706e8db0a530bfec03d91143491086a2835fcdc2a38373e0"} // Genesis
};
}

#define ALLOW_DEBUG_COMMANDS
