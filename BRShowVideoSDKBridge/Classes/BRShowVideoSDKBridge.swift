//
//  BRShowVideoSDKBridge.swift
//  BRShowVideoSDKBridge
//
//  Created by Dewa on 2026/01/28.
//  Copyright © 2026 Dewa. All rights reserved.
//

import Foundation
import UIKit

// TTSDKFramework 用于视频播放
import TTSDKFramework

// 注意: PangrowthDJX 是 Objective-C 框架，需要通过桥接头文件使用
// 如需使用 PangrowthDJX API，请在 Objective-C 代码中导入或使用 @objc 桥接

/// BRShowVideoSDKBridge 主类
/// 提供 ShowVideo SDK 的桥接功能
public class BRShowVideoSDKBridge: NSObject {
    
    // MARK: - Singleton
    
    /// 单例实例
    public static let shared = BRShowVideoSDKBridge()
    
    // MARK: - Properties
    
    /// 是否已初始化
    private(set) public var isConfigured: Bool = false
    
    /// SDK 版本号
    public var version: String {
        return "0.1.0"
    }
    
    // MARK: - Initialization
    
    private override init() {
        super.init()
    }
    
    // MARK: - Public Methods
    
    /// 配置 SDK
    /// - Parameter options: 配置选项（可选）
    public func configure(options: [String: Any]? = nil) {
        guard !isConfigured else {
            print("[BRShowVideoSDKBridge] SDK 已经配置过了")
            return
        }
        
        // TODO: 在这里添加 SDK 初始化逻辑
        
        isConfigured = true
        print("[BRShowVideoSDKBridge] SDK 配置成功，版本: \(version)")
    }
    
    /// 重置 SDK 配置
    public func reset() {
        isConfigured = false
        print("[BRShowVideoSDKBridge] SDK 已重置")
    }
}

// MARK: - Video Bridge Protocol

/// 视频桥接协议
public protocol BRShowVideoBridgeDelegate: AnyObject {
    /// 视频加载完成回调
    func videoDidLoad()
    
    /// 视频播放完成回调
    func videoDidFinishPlaying()
    
    /// 视频加载失败回调
    func videoDidFailWithError(_ error: Error)
}

// MARK: - Optional Protocol Methods

public extension BRShowVideoBridgeDelegate {
    func videoDidLoad() {}
    func videoDidFinishPlaying() {}
    func videoDidFailWithError(_ error: Error) {}
}
