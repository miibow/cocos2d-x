/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __ActionMANAGER_H__
#define __ActionMANAGER_H__

#include "cocos2d.h"
#include "CCActionObject.h"
#include "cocostudio/json/CSContentJsonDictionary.h"

namespace cocostudio {

class ActionManagerEx:public cocos2d::Object
{
public:
    
    /**
     * Default constructor
     */
    ActionManagerEx();
    
    /**
     * Default destructor
     */
    virtual ~ActionManagerEx();
    
    /**
     * Gets the static instance of ActionManager.
     */
    static ActionManagerEx* shareManager();

	 /**
     * Purges ActionManager point.
     */
	static void purgeActionManager();

	 /**
     * Gets an ActionObject with a name.
	 *
	 * @param jsonName  UI file name
     *
     * @param actionName  action name in the UI file.
     *
     * @return  ActionObject which named as the param name
     */
	ActionObject* getActionByName(const char* jsonName,const char* actionName);

	/**
     * Play an Action with a name.
	 *
	 * @param jsonName  UI file name
     *
     * @param actionName  action name in teh UIfile.
     */
	void playActionByName(const char* jsonName,const char* actionName);
    
    /*init properties with json dictionay*/
    void initWithDictionary(const char* jsonName,JsonDictionary* dic,cocos2d::Object* root);

	/**
     * Release all actions.
     *
     */
	void releaseActions();

protected:
	cocos2d::Dictionary* _pActionDic;
};

}

#endif
