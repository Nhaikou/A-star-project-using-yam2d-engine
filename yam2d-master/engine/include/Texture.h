// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// http://code.google.com/p/yam2d/
//
// Copyright (c) 2013 Mikko Romppainen
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in the
// Software without restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
// and to permit persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies
// or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <Object.h>
#include <string>

namespace yam2d
{

/**
 * Class for Texture.
 *
 * @ingroup yam2d
 * @author Mikko Romppainen (mikko@kajakbros.com) 
 */
class Texture : public Object
{
public:
	Texture(const std::string& fileName, bool allowNPOT = false);
	Texture(unsigned int nativeId, int bytesPerPixel);
	virtual ~Texture();

	void setSize(int width, int height);
	// getNative Id can be overriden in subclass for determing active texture. 
	virtual int getNativeId() const;
	int getNativeId(int index) const;

	int getWidth() const;
	int getHeight() const;
	const unsigned char* getPixel(int x, int y) const { return &m_data[(y*getWidth() + x)*getBytesPerPixel()]; }
	unsigned char* getPixel(int x, int y) { return &m_data[(y*getWidth() + x)*getBytesPerPixel()]; }
	int getBytesPerPixel() const { return m_bpp; }
	void setTransparentColor(unsigned char r, unsigned char g, unsigned char b);

	const unsigned char* getData() const {
		return &m_data[0];
	}

	void updateData() { updateData(0); }

protected:
	Texture(int numNativeTextures);

	void updateData(int nativeIdIndex);
	void setData(const unsigned char* data, int width, int height, int bpp, int nativeIdIndex);


private:
	Texture();

	unsigned int* m_nativeIds;
	int m_numNativeIds;
	int m_width;
	int m_height;
	int m_bpp;
	unsigned char* m_data;
};


}


#endif 


