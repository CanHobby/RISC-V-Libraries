/*
 * Art.h
 **  Created on: Sep. 5, 2023
 *      Author: CanHobby  ( git@canhobby.ca )
 */

#ifndef USER_CANHOBBY_H_
#define USER_CANHOBBY_H_

class CanHobby {

public:
	CanHobby();
	virtual ~CanHobby();

	int getArr( int idx = 2 );

// private:
	int arr[4] = { 99, 88, 66, 44 };

};

#endif /* USER_CANHOBBY_H_ */
