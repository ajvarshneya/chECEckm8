/*
 * uart_comm.h
 *
 * Deals with communication with remote machine.
 *
 *  Created on: Oct 19, 2016
 *      Author: Jay
 */

#ifndef UART_COMM_H_
#define UART_COMM_H_

#include "board_state.h"

/** Defines **/
#define UART_RECEIVE_BUFFER_LENGTH 32

/** Globals **/
volatile unsigned char gReceiveBuffer[UART_RECEIVE_BUFFER_LENGTH];
volatile unsigned short gReceiveBufferIndex;

/** Functions **/
// do any setup to send and receive through UART
void initUART();

// send a piece movement to chess server
void send(piece_movement* move);
// receive a piece movement response from chess server
// if other_move is filled, that move should be executed after the first move
// if a move has (0xFF, 0xFF) as a destination, then it represents a capture
signed char receive(piece_movement* move, piece_movement* other_move);

// DEBUG functions
void helloWorldSend();
void helloWorldReceive();
void debugGameLoop();

#endif /* UART_COMM_H_ */