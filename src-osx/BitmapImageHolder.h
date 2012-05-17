// BitmapImageHolder.h
// this file is part of Context Free
// ---------------------
// Copyright (C) 2009 John Horigan - john@glyphic.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
// 
// John Horigan can be contacted at john@glyphic.com or at
// John Horigan, 1209 Villa St., Mountain View, CA 94041-1123, USA
//
//


#ifndef _H_BitmapImageHolder
#define _H_BitmapImageHolder

@class NSString;
@class NSMutableData;
@class NSBitmapImageRep;
#include "aggCanvas.h"

@interface BitmapImageHolder : NSObject
{
    // Attributes
    aggCanvas::PixelFormat _aggPixFmt;
    NSString*       _colorSpace;
    BOOL            _hasAlpha;
    int             _bitsPerSample;
    int             _pixelsWide;
    int             _pixelsHigh;  
    unsigned int    _bytesPerRow;
    unsigned int    _bitsPerPixel; 
    unsigned int    _samplesPerPixel;
    BOOL            _isPlanar;
    unsigned char   *_imagePlanes[5];
    NSMutableData   *_imageData;
}

//
// Allocating and Initializing a New BitmapImageHolder Object 
//
- (id) initWithAggPixFmt: (aggCanvas::PixelFormat)fmt
              pixelsWide: (NSInteger)width
              pixelsHigh: (NSInteger)height;

//
// Getting Information about the Image 
//
- (int) bitsPerPixel;
- (int) samplesPerPixel;
- (BOOL) isPlanar;
- (int) numberOfPlanes;
- (int) bytesPerPlane;
- (int) bytesPerRow;
- (int) bitsPerSample;
- (NSString *) colorSpaceName;
- (BOOL) hasAlpha;
- (int) pixelsHigh;
- (int) pixelsWide;
- (aggCanvas::PixelFormat) aggPixelFormat;

//
// Getting Image Data 
//
- (unsigned char*) bitmapData;
- (void) getBitmapDataPlanes: (unsigned char**)data;


//
// Getting an NSBitmapImageReps
//
- (NSBitmapImageRep*) newImageRep;
- (NSBitmapImageRep*) getImageRep;
- (NSBitmapImageRep*) getImageRepCropped: (NSRect)cropRect;
@end

#endif // _H_BitmapImageHolder
