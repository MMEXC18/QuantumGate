// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#include "pch.h"
#include "..\Socks5Extender\Socks5Extender.h"

QuantumGate::Result<QuantumGate::Vector<std::shared_ptr<QuantumGate::Extender>>> MakeQuantumGateExtenders()
{
	try
	{
		auto extender = std::make_shared<QuantumGate::Socks5Extender::Extender>();

		QuantumGate::Vector<std::shared_ptr<QuantumGate::Extender>> extenders;
		extenders.emplace_back(std::move(extender));

		return { std::move(extenders) };
	}
	catch (...) {}

	return QuantumGate::ResultCode::Failed;
}