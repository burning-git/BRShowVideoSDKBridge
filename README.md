# BRShowVideoSDKBridge

[![Version](https://img.shields.io/cocoapods/v/BRShowVideoSDKBridge.svg?style=flat)](https://cocoapods.org/pods/BRShowVideoSDKBridge)
[![License](https://img.shields.io/cocoapods/l/BRShowVideoSDKBridge.svg?style=flat)](https://cocoapods.org/pods/BRShowVideoSDKBridge)
[![Platform](https://img.shields.io/cocoapods/p/BRShowVideoSDKBridge.svg?style=flat)](https://cocoapods.org/pods/BRShowVideoSDKBridge)

## 简介

BRShowVideoSDKBridge 是一个用于 iOS 的 ShowVideo SDK 桥接库，提供简洁的 API 接口来集成视频相关功能。

## 要求

- iOS 11.0+
- Swift 5.0+
- Xcode 12.0+

## 安装

### CocoaPods

BRShowVideoSDKBridge 可以通过 [CocoaPods](https://cocoapods.org) 安装。

**注意：** 本库依赖火山引擎私有源，需要在 Podfile 顶部添加以下 source：

```ruby
# 私有源
source 'https://github.com/burning-git/volcengine-specs.git'
# CocoaPods 官方源
source 'https://cdn.cocoapods.org/'
```

然后添加 pod：

```ruby
pod 'BRShowVideoSDKBridge'
```

完整 Podfile 示例：

```ruby
# 私有源
source 'https://github.com/burning-git/volcengine-specs.git'
# CocoaPods 官方源
source 'https://cdn.cocoapods.org/'

use_frameworks!

platform :ios, '11.0'

target 'YourApp' do
  pod 'BRShowVideoSDKBridge'
end
```

然后运行：

```bash
$ pod install
```

### 依赖说明

本库依赖以下组件：
- `PangrowthX/shortplay` 2.9.0.0
- `TTSDKFramework/Player-SR` 1.42.3.4-premium

## 使用方法

### 导入库

```swift
import BRShowVideoSDKBridge
```

### 初始化

```swift
BRShowVideoSDKBridge.shared.configure()
```

## 示例项目

要运行示例项目，首先克隆仓库，然后在 Example 目录下运行 `pod install`。

## 作者

Dewa, 2496883739@qq.com

## 许可证

BRShowVideoSDKBridge 基于 MIT 许可证开源。详情请查看 LICENSE 文件。
