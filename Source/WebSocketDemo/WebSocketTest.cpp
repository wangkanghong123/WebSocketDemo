// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketTest.h"

void UWebSocketTest::connectWS()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("connectWS"));

	const FString serverURL = TEXT("ws://172.20.12.62:15000/post");
	const FString serverProtocol = TEXT("ws");

	socketPtr = FWebSocketsModule::Get().CreateWebSocket(serverURL, serverProtocol);

	socketPtr->OnConnected().AddLambda([]()->void {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("OnConnected Success"));
	});

	socketPtr->OnConnectionError().AddLambda([](const FString &error)->void {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("OnConnectionError"));
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, error);
	});

	socketPtr->OnClosed().AddLambda([](int32 statusCode, const FString& reason, bool bWasClean)->void {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("OnClosed"));
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, reason);
	});

	socketPtr->OnMessage().AddLambda([](const FString& message)->void {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("OnMessage"));
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, message);
	});

	socketPtr->OnMessageSent().AddLambda([](const FString& messageStr)->void {
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("OnMessageSent"));
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, messageStr);
	});

	socketPtr->Connect();
}

void UWebSocketTest::sendWS()
{
	const FString strMessage = TEXT("Hello there !");
	socketPtr->Send(strMessage);
}

void UWebSocketTest::closeWS()
{
	socketPtr->Close();
}
