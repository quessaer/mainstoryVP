//
//  ViewController.swift
//  MainStoryBoardVestPin
//
//  Created by J.T. Kim on 2021/11/10.
//

import UIKit


class ViewController: UIViewController {
 

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        versionCheck()
        self.navigationItem.title = "renewalkeypad"
    }
    

    func versionCheck() {
        print("Vikie Version: \(VikieNumberViewController.getVersion())")
        print("VestPIN Version: \(VestPIN.getVersion())")
    }


}
