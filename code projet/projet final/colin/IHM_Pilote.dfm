object IHM: TIHM
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
  object Button1: TButton
    Left = 8
    Top = 308
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button5: TButton
    Left = 8
    Top = 339
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 1
    OnClick = Button5Click
  end
  object GroupBox1: TGroupBox
    Left = 40
    Top = 8
    Width = 249
    Height = 128
    Caption = 'Connexion'
    TabOrder = 2
    object shpConnexion: TShape
      Left = 184
      Top = 48
      Width = 41
      Height = 35
    end
    object btnConnexion: TButton
      Left = 48
      Top = 80
      Width = 89
      Height = 25
      Caption = 'connexion'
      TabOrder = 0
      OnClick = btnConnexionClick
    end
    object edtIp: TEdit
      Left = 32
      Top = 21
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '192.168.64.200'
    end
    object edtPort: TEdit
      Left = 32
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 2
      Text = '502'
    end
    object btnDéconnexion: TButton
      Left = 48
      Top = 80
      Width = 89
      Height = 25
      Caption = 'd'#233'connexion'
      TabOrder = 3
      Visible = False
      OnClick = btnDéconnexionClick
    end
  end
  object Action: TGroupBox
    Left = 328
    Top = 8
    Width = 280
    Height = 128
    Caption = 'Action'
    TabOrder = 3
    Visible = False
    object btnActiveTapis: TButton
      Left = 64
      Top = 35
      Width = 144
      Height = 25
      Caption = 'activer lecture du tapis'
      TabOrder = 0
      OnClick = btnActiveTapisClick
    end
    object btnDesactiveTapis: TButton
      Left = 64
      Top = 35
      Width = 145
      Height = 25
      Caption = 'd'#233'sactiver lecture du tapis'
      TabOrder = 1
      Visible = False
      OnClick = btnDesactiveTapisClick
    end
    object btnAllumerTapis: TButton
      Left = 64
      Top = 74
      Width = 145
      Height = 25
      Caption = 'allumer tapis'
      TabOrder = 2
      OnClick = btnAllumerTapisClick
    end
    object btnEteindreTapis: TButton
      Left = 64
      Top = 74
      Width = 145
      Height = 25
      Caption = #233'teindre tapis'
      TabOrder = 3
      Visible = False
      OnClick = btnEteindreTapisClick
    end
  end
  object Button7: TButton
    Left = 8
    Top = 365
    Width = 75
    Height = 25
    Caption = 'Button7'
    TabOrder = 4
    OnClick = Button7Click
  end
  object Edit1: TEdit
    Left = 89
    Top = 365
    Width = 121
    Height = 21
    TabOrder = 5
    Text = 'Edit1'
  end
  object Etat: TGroupBox
    Left = 89
    Top = 142
    Width = 480
    Height = 133
    Caption = 'Etat'
    TabOrder = 6
    Visible = False
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
end
