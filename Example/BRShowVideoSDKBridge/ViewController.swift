//
//  ViewController.swift
//  BRShowVideoSDKBridge
//
//  Created by Dewa on 2026/01/28.
//  Copyright © 2026 Dewa. All rights reserved.
//

import UIKit
import BRShowVideoSDKBridge


class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // 配置 SDK
        BRShowVideoSDKBridge.shared.configure()
        
        // 打印版本号
        print("BRShowVideoSDKBridge 版本: \(BRShowVideoSDKBridge.shared.version)")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
}
