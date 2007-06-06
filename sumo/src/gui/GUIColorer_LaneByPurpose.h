/****************************************************************************/
/// @file    GUIColorer_LaneByPurpose.h
/// @author  Daniel Krajzewicz
/// @date    Fri, 29.04.2005
/// @version $Id$
///
//
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// copyright : (C) 2001-2007
//  by DLR (http://www.dlr.de/) and ZAIK (http://www.zaik.uni-koeln.de/AFS)
/****************************************************************************/
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef GUIColorer_LaneByPurpose_h
#define GUIColorer_LaneByPurpose_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <utils/gui/drawer/GUIBaseColorer.h>
#include <utils/gfx/RGBColor.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include <microsim/MSEdge.h>
#include <guisim/GUILaneWrapper.h>
#include <GL/gl.h>

// ===========================================================================
// class definitions
// ===========================================================================
/**
 *
 */
template<class _T>
class GUIColorer_LaneByPurpose : public GUIBaseColorer<_T>
{
public:
    GUIColorer_LaneByPurpose()
    { }

    virtual ~GUIColorer_LaneByPurpose()
    { }

    void setGlColor(const _T& i) const
    {
        switch (i.getPurpose()) {
        case MSEdge::EDGEFUNCTION_NORMAL:
            glColor3f(0, 0, 0);
            return;
        case MSEdge::EDGEFUNCTION_SOURCE:
            glColor3f(0, 1, 0);
            return;
        case MSEdge::EDGEFUNCTION_SINK:
            glColor3f(1, 0, 0);
            return;
        case MSEdge::EDGEFUNCTION_INTERNAL:
            glColor3f(0, 0, 1);
            return;
        default:
            // hmmmm - should not happen
            glColor3f(1, 1, 0);
            return;
        }
    }

    void setGlColor(SUMOReal val) const
    {
        glColor3d(val, val, val);
    }

    virtual ColorSetType getSetType() const
    {
        return CST_STATIC; // !!! (should be "set")
    }


};


#endif

/****************************************************************************/

