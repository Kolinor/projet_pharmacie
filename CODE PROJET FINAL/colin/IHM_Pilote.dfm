﻿object IHM: TIHM
  Left = 0
  Top = 0
  Caption = 'IHM'
  ClientHeight = 398
  ClientWidth = 849
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lblIp: TGroupBox
    Left = 40
    Top = 8
    Width = 249
    Height = 128
    Caption = 'Connexion'
    TabOrder = 0
    object shpConnexion: TShape
      Left = 197
      Top = 46
      Width = 41
      Height = 35
      Brush.Color = clRed
    end
    object Label1: TLabel
      Left = 26
      Top = 22
      Width = 20
      Height = 13
      Caption = 'Ip : '
    end
    object lblPort: TLabel
      Left = 15
      Top = 51
      Width = 27
      Height = 13
      Caption = 'Port :'
    end
    object btnConnexion: TButton
      Left = 76
      Top = 75
      Width = 89
      Height = 25
      Caption = 'connexion'
      TabOrder = 0
    end
    object edtIp: TEdit
      Left = 59
      Top = 21
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '192.168.64.200'
    end
    object edtPort: TEdit
      Left = 59
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 2
      Text = '502'
    end
    object btnDéconnexion: TButton
      Left = 76
      Top = 75
      Width = 89
      Height = 25
      Caption = 'd'#233'connexion'
      TabOrder = 3
      Visible = False
      OnClick = btnDéconnexionClick
    end
  end
  object Etat: TGroupBox
    Left = 89
    Top = 142
    Width = 480
    Height = 133
    Caption = 'Etat'
    TabOrder = 1
    object lblTapis: TLabel
      Left = 27
      Top = 21
      Width = 32
      Height = 13
      Caption = 'Tapis :'
    end
    object lblCapteur1: TLabel
      Left = 91
      Top = 21
      Width = 55
      Height = 13
      Caption = 'Capteur 1 :'
    end
    object lblCapteur2: TLabel
      Left = 172
      Top = 21
      Width = 55
      Height = 13
      Caption = 'Capteur 2 :'
    end
    object lblPiston1: TLabel
      Left = 261
      Top = 21
      Width = 45
      Height = 13
      Caption = 'Piston 1 :'
    end
    object lblPiston2: TLabel
      Left = 333
      Top = 21
      Width = 45
      Height = 13
      Caption = 'Piston 2 :'
    end
    object lblPiston3: TLabel
      Left = 413
      Top = 21
      Width = 45
      Height = 13
      Caption = 'Piston 3 :'
    end
    object shpTapis: TShape
      Left = 27
      Top = 48
      Width = 48
      Height = 41
      Brush.Color = clRed
    end
    object shpCapteur1: TShape
      Left = 98
      Top = 48
      Width = 48
      Height = 41
      Brush.Color = clRed
    end
    object shpCapteur2: TShape
      Left = 179
      Top = 48
      Width = 48
      Height = 41
      Brush.Color = clRed
    end
    object shpPiston1: TShape
      Left = 258
      Top = 48
      Width = 48
      Height = 41
      Brush.Color = clRed
    end
    object shpPiston2: TShape
      Left = 330
      Top = 48
      Width = 48
      Height = 41
      Brush.Color = clRed
    end
    object shpPiston3: TShape
      Left = 410
      Top = 48
      Width = 48
      Height = 41
      Brush.Color = clRed
    end
  end
  object tmRS232: TTimer
    Enabled = False
    OnTimer = tmRS232Timer
    Left = 648
    Top = 32
  end
end
