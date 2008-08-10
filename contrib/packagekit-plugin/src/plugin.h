/* -*- mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include <X11/Xlib.h>

#include "contents.h"
#include "pluginbase.h"

class PkpPluginInstance : public nsPluginInstanceBase
{
public:
    PkpPluginInstance(NPP aInstance, const char *displayName, const char *packageNames, const char *desktopNames);
    virtual ~PkpPluginInstance();

    NPBool init(NPWindow* aWindow);
    void shut();
    NPBool isInitialized() {return mInitialized;}
    NPError GetValue(NPPVariable variable, void *value);
    NPError SetWindow(NPWindow* aWindow);
    uint16 HandleEvent(void *event);

    void refresh();

    int getX() { return mX; }
    int getY() { return mY; }
    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }

private:
    NPP mInstance;
    NPBool mInitialized;

    PkpContents mContents;

    Window mWindow;
    Display *mDisplay;
    int mX, mY;
    int mWidth, mHeight;
    Visual* mVisual;
    Colormap mColormap;
    unsigned int mDepth;
};

#endif // __PLUGIN_H__
