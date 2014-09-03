// Copyright 2012-2014 UX Productivity Pty Ltd
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "core_helper.h"
#include "core_datacapsule.h"
#include "WordSettings.h"
#include "DFDOM.h"
#include "DFXML.h"
#include "WordPackage.h"
#include "WordConverter.h"
#include "DFCommon.h"

static Tag WordSettings_Children[] = {
    WORD_WRITEPROTECTION,
    WORD_VIEW,
    WORD_ZOOM,
    WORD_REMOVEPERSONALINFORMATION,
    WORD_REMOVEDATEANDTIME,
    WORD_DONOTDISPLAYPAGEBOUNDARIES,
    WORD_DISPLAYBACKGROUNDSHAPE,
    WORD_PRINTPOSTSCRIPTOVERTEXT,
    WORD_PRINTFRACTIONALCHARACTERWIDTH,
    WORD_PRINTFORMSDATA,
    WORD_EMBEDTRUETYPEFONTS,
    WORD_EMBEDSYSTEMFONTS,
    WORD_SAVESUBSETFONTS,
    WORD_SAVEFORMSDATA,
    WORD_MIRRORMARGINS,
    WORD_ALIGNBORDERSANDEDGES,
    WORD_BORDERSDONOTSURROUNDHEADER,
    WORD_BORDERSDONOTSURROUNDFOOTER,
    WORD_GUTTERATTOP,
    WORD_HIDESPELLINGERRORS,
    WORD_HIDEGRAMMATICALERRORS,
    WORD_ACTIVEWRITINGSTYLE,
    WORD_PROOFSTATE,
    WORD_FORMSDESIGN,
    WORD_ATTACHEDTEMPLATE,
    WORD_LINKSTYLES,
    WORD_STYLEPANEFORMATFILTER,
    WORD_STYLEPANESORTMETHOD,
    WORD_DOCUMENTTYPE,
    WORD_MAILMERGE,
    WORD_REVISIONVIEW,
    WORD_TRACKREVISIONS,
    WORD_DONOTTRACKMOVES,
    WORD_DONOTTRACKFORMATTING,
    WORD_DOCUMENTPROTECTION,
    WORD_AUTOFORMATOVERRIDE,
    WORD_STYLELOCKTHEME,
    WORD_STYLELOCKQFSET,
    WORD_DEFAULTTABSTOP,
    WORD_AUTOHYPHENATION,
    WORD_CONSECUTIVEHYPHENLIMIT,
    WORD_HYPHENATIONZONE,
    WORD_DONOTHYPHENATECAPS,
    WORD_SHOWENVELOPE,
    WORD_SUMMARYLENGTH,
    WORD_CLICKANDTYPESTYLE,
    WORD_DEFAULTTABLESTYLE,
    WORD_EVENANDODDHEADERS,
    WORD_BOOKFOLDREVPRINTING,
    WORD_BOOKFOLDPRINTING,
    WORD_BOOKFOLDPRINTINGSHEETS,
    WORD_DRAWINGGRIDHORIZONTALSPACING,
    WORD_DRAWINGGRIDVERTICALSPACING,
    WORD_DISPLAYHORIZONTALDRAWINGGRIDEVERY,
    WORD_DISPLAYVERTICALDRAWINGGRIDEVERY,
    WORD_DONOTUSEMARGINSFORDRAWINGGRIDORIGIN,
    WORD_DRAWINGGRIDHORIZONTALORIGIN,
    WORD_DRAWINGGRIDVERTICALORIGIN,
    WORD_DONOTSHADEFORMDATA,
    WORD_NOPUNCTUATIONKERNING,
    WORD_CHARACTERSPACINGCONTROL,
    WORD_PRINTTWOONONE,
    WORD_STRICTFIRSTANDLASTCHARS,
    WORD_NOLINEBREAKSAFTER,
    WORD_NOLINEBREAKSBEFORE,
    WORD_SAVEPREVIEWPICTURE,
    WORD_DONOTVALIDATEAGAINSTSCHEMA,
    WORD_SAVEINVALIDXML,
    WORD_IGNOREMIXEDCONTENT,
    WORD_ALWAYSSHOWPLACEHOLDERTEXT,
    WORD_DONOTDEMARCATEINVALIDXML,
    WORD_SAVEXMLDATAONLY,
    WORD_USEXSLTWHENSAVING,
    WORD_SAVETHROUGHXSLT,
    WORD_SHOWXMLTAGS,
    WORD_ALWAYSMERGEEMPTYNAMESPACE,
    WORD_UPDATEFIELDS,
    WORD_HDRSHAPEDEFAULTS,
    WORD_FOOTNOTEPR,
    WORD_ENDNOTEPR,
    WORD_COMPAT,
    WORD_DOCVARS,
    WORD_RSIDS,
    MATH_MATHPR,
    WORD_ATTACHEDSCHEMA,
    WORD_THEMEFONTLANG,
    WORD_CLRSCHEMEMAPPING,
    WORD_DONOTINCLUDESUBDOCSINSTATS,
    WORD_DONOTAUTOCOMPRESSPICTURES,
    WORD_FORCEUPGRADE,
    WORD_CAPTIONS,
    WORD_READMODEINKLOCKDOWN,
    WORD_SMARTTAGTYPE,
    SL_SCHEMALIBRARY,
    WORD_SHAPEDEFAULTS,
    WORD_DONOTEMBEDSMARTTAGS,
    WORD_DECIMALSYMBOL,
    WORD_LISTSEPARATOR,
    0,
};

void Word_updateSettings(WordPackage *package, int updateFields)
{
    assert(package->settings != NULL);
    assert(package->settings->root != NULL);

    DFNode *children[PREDEFINED_TAG_COUNT];
    childrenToArray(package->settings->root,children);

    if (updateFields) {
        if (children[WORD_UPDATEFIELDS] == NULL)
            children[WORD_UPDATEFIELDS] = DFCreateElement(package->settings,WORD_UPDATEFIELDS);
        DFSetAttribute(children[WORD_UPDATEFIELDS],WORD_VAL,"true");
    }

    replaceChildrenFromArray(package->settings->root,children,WordSettings_Children);
}
