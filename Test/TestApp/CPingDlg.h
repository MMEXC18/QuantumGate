// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#pragma once

#include "CDialogBase.h"

class CPingDlg final : public CDialogBase
{
	DECLARE_DYNAMIC(CPingDlg)

public:
	CPingDlg(CWnd* pParent = nullptr);
	virtual ~CPingDlg();

	const QuantumGate::IPAddress& GetIPAddress() const noexcept { return m_IP; }
	UInt8 GetBufferSize() const noexcept { return m_BufferSize; }
	std::chrono::seconds GetTTL() const noexcept { return m_TTL; }
	std::chrono::milliseconds GetTimeout() const noexcept { return m_Timeout; }

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedOk();

private:
	QuantumGate::IPAddress m_IP;
	UInt8 m_BufferSize{ 0 };
	std::chrono::seconds m_TTL{ 0 };
	std::chrono::milliseconds m_Timeout{ 0 };
};
