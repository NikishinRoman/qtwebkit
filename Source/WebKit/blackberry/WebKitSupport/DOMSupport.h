/*
 * Copyright (C) 2011, 2012 Research In Motion Limited. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef DOMSupport_h
#define DOMSupport_h

#include "IntPoint.h"
#include "IntRect.h"

#include <wtf/Vector.h>

namespace WTF {
class String;
}

namespace WebCore {
class Element;
class FloatQuad;
class Frame;
class HTMLTextFormControlElement;
class Node;
class Position;
class Range;
class VisibleSelection;
}

namespace BlackBerry {
namespace WebKit {
namespace DOMSupport {

enum AttributeState { On, Off, Default };

bool isElementTypePlugin(const WebCore::Element*);

bool isTextInputElement(WebCore::Element*);
bool isTextBasedContentEditableElement(WebCore::Element*);
bool isPasswordElement(const WebCore::Element*);

bool isPopupInputField(const WebCore::Element*);
bool isDateTimeInputField(const WebCore::Element*);
bool isColorInputField(const WebCore::Element*);
AttributeState elementSupportsAutocorrect(const WebCore::Element*);

WTF::String inputElementText(WebCore::Element*);

WebCore::HTMLTextFormControlElement* toTextControlElement(WebCore::Node*);

WebCore::IntRect transformedBoundingBoxForRange(const WebCore::Range&);
void visibleTextQuads(const WebCore::Range&, WTF::Vector<WebCore::FloatQuad>& quads, bool useSelectionHeight = false);

WebCore::VisibleSelection visibleSelectionForRangeInputElement(WebCore::Element*, int start, int end);
WebCore::VisibleSelection visibleSelectionForInputElement(WebCore::Element*);

WebCore::Node* DOMContainerNodeForPosition(const WebCore::Position&);
bool isPositionInNode(WebCore::Node*, const WebCore::Position&);

AttributeState elementSupportsAutocomplete(const WebCore::Element*);
bool elementIdOrNameIndicatesNoAutocomplete(const WebCore::Element*);

WebCore::IntPoint convertPointToFrame(const WebCore::Frame* sourceFrame, const WebCore::Frame* targetFrame, const WebCore::IntPoint& sourcePoint);

static const WebCore::IntPoint InvalidPoint = WebCore::IntPoint(-1, -1);

WebCore::VisibleSelection visibleSelectionForClosestActualWordStart(const WebCore::VisibleSelection&);

} // DOMSupport
} // WebKit
} // BlackBerry

#endif // DOMSupport_h