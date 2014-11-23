// Copyright 2013 Dolphin Emulator Project
// Licensed under GPLv2
// Refer to the license.txt file included.

#include <string>
#include <vector>
#include <wx/arrstr.h>
#include <wx/button.h>
#include <wx/chartype.h>
#include <wx/defs.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gbsizer.h>
#include <wx/gdicmn.h>
#include <wx/msgdlg.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/spinbutt.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/translation.h>
#include <wx/windowid.h>

#include "Common/CommonTypes.h"
#include "Core/RmObjEngine.h"
#include "DolphinWX/RmObjAddEdit.h"
#include "DolphinWX/WxUtils.h"

CRmObjAddEdit::CRmObjAddEdit(int _selection, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& position, const wxSize& size, long style)
	: wxDialog(parent, id, title, position, size, style)
{
	selection = _selection;
	CreateGUIControls(selection);

	Bind(wxEVT_BUTTON, &CRmObjAddEdit::SaveRmObjData, this, wxID_OK);
}

CRmObjAddEdit::~CRmObjAddEdit()
{
}

void CRmObjAddEdit::CreateGUIControls(int _selection)
{
	wxString currentName = _("<Insert name here>");

	if (_selection == -1)
	{
		tempEntries.clear();
		tempEntries.push_back(RmObjEngine::RmObjEntry(RmObjEngine::RMOBJ_16BIT, 0x00000000));
	}
	else
	{
		currentName = StrToWxStr(rmObjCodes.at(_selection).name);
		tempEntries = rmObjCodes.at(_selection).entries;
	}

	itCurEntry = tempEntries.begin();

	wxBoxSizer* sEditRmObj = new wxBoxSizer(wxVERTICAL);

	wxStaticText* EditRmObjNameText = new wxStaticText(this, wxID_ANY, _("Name:"));
	EditRmObjName = new wxTextCtrl(this, wxID_ANY);
	EditRmObjName->SetValue(currentName);

	wxArrayString wxArrayStringFor_EditRmObjType;
	for (int i = 0; i < 4; ++i)
		wxArrayStringFor_EditRmObjType.Add(StrToWxStr(RmObjEngine::RmObjTypeStrings[i]));
	EditRmObjType = new wxRadioBox(this, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, wxArrayStringFor_EditRmObjType, 4, wxRA_SPECIFY_COLS);
	EditRmObjType->SetSelection((int)tempEntries.at(0).type);

	wxStaticText* EditRmObjValueText = new wxStaticText(this, wxID_ANY, _("Value:"));
	EditRmObjValue = new wxTextCtrl(this, wxID_ANY);
	if (RmObjEngine::GetRmObjTypeCharLength(tempEntries.at(0).type) <= 8)
		EditRmObjValue->SetValue(wxString::Format("%0*X", RmObjEngine::GetRmObjTypeCharLength(tempEntries.at(0).type), (u32)tempEntries.at(0).value));
	else 
		EditRmObjValue->SetValue(wxString::Format("%0*X%08X", RmObjEngine::GetRmObjTypeCharLength(tempEntries.at(0).type)-8, (u32)((tempEntries.at(0).value & 0xffffffff00000000) >> 32), (u32)((tempEntries.at(0).value & 0xffffffff))));

	wxBoxSizer* sEditRmObjName = new wxBoxSizer(wxHORIZONTAL);
	sEditRmObjName->Add(EditRmObjNameText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
	sEditRmObjName->Add(EditRmObjName, 1, wxEXPAND|wxALL, 5);
	sEditRmObj->Add(sEditRmObjName, 0, wxEXPAND);
	sbEntry = new wxStaticBoxSizer(wxVERTICAL, this, wxString::Format(_("Object Removal Code")));

	wxGridBagSizer* sgEntry = new wxGridBagSizer(0, 0);
	sgEntry->Add(EditRmObjType, wxGBPosition(0, 0), wxGBSpan(1, 2), wxEXPAND|wxALL, 5);
	sgEntry->Add(EditRmObjValueText, wxGBPosition(1, 0), wxGBSpan(1, 1), wxALIGN_CENTER_VERTICAL|wxALL, 5);
	sgEntry->Add(EditRmObjValue, wxGBPosition(1, 1), wxGBSpan(1, 1), wxEXPAND|wxALL, 5);
	sgEntry->AddGrowableCol(1);

	sbEntry->Add(sgEntry, 0, wxEXPAND);

	sEditRmObj->Add(sbEntry, 0, wxEXPAND|wxALL, 5);
	sEditRmObj->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxEXPAND|wxLEFT|wxRIGHT|wxBOTTOM, 5);
	SetSizerAndFit(sEditRmObj);
	SetFocus();
}

void CRmObjAddEdit::SaveRmObjData(wxCommandEvent& event)
{
	if (!UpdateTempEntryData(itCurEntry))
		return;

	if (selection == -1)
	{
		RmObjEngine::RmObj newRmObj;
		newRmObj.name = WxStrToStr(EditRmObjName->GetValue());
		newRmObj.entries = tempEntries;
		newRmObj.active = true;

		rmObjCodes.push_back(newRmObj);
	}
	else
	{
		rmObjCodes.at(selection).name = WxStrToStr(EditRmObjName->GetValue());
		rmObjCodes.at(selection).entries = tempEntries;
	}

	AcceptAndClose();
	event.Skip();
}

bool CRmObjAddEdit::UpdateTempEntryData(std::vector<RmObjEngine::RmObjEntry>::iterator iterEntry)
{
	unsigned long long value;
	bool parsed_ok = true;

	RmObjEngine::RmObjType tempType =
	(*iterEntry).type = (RmObjEngine::RmObjType)EditRmObjType->GetSelection();

	if (EditRmObjValue->GetValue().ToULongLong(&value, 16))
	{
		(*iterEntry).value = value;
		if (tempType == RmObjEngine::RMOBJ_16BIT && value > 0xffff)
			parsed_ok = false;
		else if (tempType == RmObjEngine::RMOBJ_32BIT && value > 0xffffffff)
			parsed_ok = false;
		else if (tempType == RmObjEngine::RMOBJ_48BIT && value > 0xffffffffffff)
			parsed_ok = false;
		else if (tempType == RmObjEngine::RMOBJ_64BIT && value > 0xffffffffffffffff)
			parsed_ok = false;
	}
	else
	{
		parsed_ok = false;
	}

	if (!parsed_ok)
	{
		wxMessageBox(_("Value too large or a non hex (0-9 or A-F) character entered.\nEntry not modified."), _("Error"));
	}

	return parsed_ok;
}