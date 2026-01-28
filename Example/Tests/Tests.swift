//
//  Tests.swift
//  BRShowVideoSDKBridge_Tests
//
//  Created by Dewa on 2026/01/28.
//  Copyright © 2026 Dewa. All rights reserved.
//

import XCTest
import BRShowVideoSDKBridge

class Tests: XCTestCase {
    
    override func setUp() {
        super.setUp()
    }
    
    override func tearDown() {
        super.tearDown()
    }
    
    func testSharedInstance() {
        let instance1 = BRShowVideoSDKBridge.shared
        let instance2 = BRShowVideoSDKBridge.shared
        XCTAssertTrue(instance1 === instance2, "单例实例应该相同")
    }
    
    func testVersion() {
        let version = BRShowVideoSDKBridge.shared.version
        XCTAssertFalse(version.isEmpty, "版本号不应为空")
    }
    
    func testConfigure() {
        BRShowVideoSDKBridge.shared.reset()
        XCTAssertFalse(BRShowVideoSDKBridge.shared.isConfigured)
        
        BRShowVideoSDKBridge.shared.configure()
        XCTAssertTrue(BRShowVideoSDKBridge.shared.isConfigured)
    }
    
    func testVideoPlayer() {
        let player = BRShowVideoPlayer()
        XCTAssertFalse(player.isPlaying)
        XCTAssertNil(player.currentVideoURL)
    }
}
