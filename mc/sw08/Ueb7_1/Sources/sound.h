/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         Sound player
 * \file
 * \author        Leandro Kressebuch, Christian Jost
 * \date          11.10.2012
 *
 * \b Language:   Ansi-C \n\n
 * \b Target:     MC Car \n
 *
 * $Id: sound.h 508 2013-10-31 08:58:42Z zajost $
 *--------------------------------------------------------------------
 */
#ifndef SOUND_H
#define SOUND_H


bool soundIsPlaying(void);
void soundTooglePlayPause(void);

void soundStart(void);
void soundStop(void);

void soundPlay(const char *soundFile);

#endif /* SOUND_H_ */
