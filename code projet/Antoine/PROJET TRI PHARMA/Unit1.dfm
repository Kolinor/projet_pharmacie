object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 658
  ClientWidth = 1362
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Lbl_Title: TLabel
    Left = 543
    Top = 8
    Width = 412
    Height = 50
    Caption = 'IHM Base de Donn'#233'e'
    Font.Charset = CHINESEBIG5_CHARSET
    Font.Color = clWindowText
    Font.Height = 50
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
  end
  object Rbt_Automate: TRadioButton
    Left = 520
    Top = 96
    Width = 129
    Height = 17
    Caption = 'Parametre automate'
    TabOrder = 1
    Visible = False
    OnClick = Rbt_AutomateClick
  end
  object Rbt_addMedicament: TRadioButton
    Left = 104
    Top = 96
    Width = 121
    Height = 17
    Caption = 'Ajout'#233' M'#233'dicament'
    TabOrder = 0
    Visible = False
    OnClick = Rbt_addMedicamentClick
  end
  object Grb_Automate: TGroupBox
    Left = 392
    Top = 135
    Width = 410
    Height = 122
    TabOrder = 2
    object lbl_cle: TLabel
      Left = 16
      Top = 43
      Width = 15
      Height = 13
      Caption = 'Cle'
    end
    object lbl_value: TLabel
      Left = 16
      Top = 94
      Width = 26
      Height = 13
      Caption = 'Value'
    end
    object Edit_cle: TEdit
      Left = 56
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit_value: TEdit
      Left = 56
      Top = 91
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Btn_sendAutomate: TButton
      Left = 332
      Top = 86
      Width = 75
      Height = 25
      Caption = 'Envoyer'
      TabOrder = 2
      OnClick = Btn_sendAutomateClick
    end
  end
  object Grb_addMedicament: TGroupBox
    Left = 8
    Top = 135
    Width = 362
    Height = 354
    TabOrder = 3
    object Lbl_Nom_Medicament: TLabel
      Left = 19
      Top = 156
      Width = 96
      Height = 13
      Caption = 'Nom du m'#233'dicament'
    end
    object Lbl_Hauteur: TLabel
      Left = 19
      Top = 183
      Width = 39
      Height = 13
      Caption = 'Hauteur'
    end
    object Lbl_Largeur: TLabel
      Left = 19
      Top = 210
      Width = 37
      Height = 13
      Caption = 'Largeur'
    end
    object Lbl_Code_Barre: TLabel
      Left = 19
      Top = 267
      Width = 54
      Height = 13
      Caption = 'Code Barre'
    end
    object Lbl_Prix: TLabel
      Left = 19
      Top = 296
      Width = 18
      Height = 13
      Caption = 'Prix'
    end
    object Lbl_Longueur: TLabel
      Left = 19
      Top = 240
      Width = 45
      Height = 13
      Caption = 'Longueur'
    end
    object Edit_hauteur: TEdit
      Left = 121
      Top = 180
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit_largeur: TEdit
      Left = 121
      Top = 207
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Edit_nomMedicament: TEdit
      Left = 121
      Top = 153
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit_longueur: TEdit
      Left = 121
      Top = 237
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Edit_codeBarre: TEdit
      Left = 121
      Top = 264
      Width = 121
      Height = 21
      TabOrder = 4
    end
    object Edit_prix: TEdit
      Left = 121
      Top = 291
      Width = 121
      Height = 21
      TabOrder = 5
    end
    object Btn_sendMedicament: TButton
      Left = 272
      Top = 288
      Width = 75
      Height = 25
      Caption = 'Envoyer'
      TabOrder = 6
      OnClick = Btn_sendMedicamentClick
    end
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 495
    Width = 305
    Height = 121
    TabOrder = 4
    ColWidths = (
      64
      88
      60
      815
      815)
  end
  object Grb_Ordonance: TGroupBox
    Left = 808
    Top = 135
    Width = 354
    Height = 354
    TabOrder = 5
    object Btn_sendOrdonnance: TButton
      Left = 264
      Top = 288
      Width = 75
      Height = 25
      Caption = 'Envoyer'
      TabOrder = 0
    end
  end
  object Rbt_Ordonnance: TRadioButton
    Left = 944
    Top = 96
    Width = 113
    Height = 17
    Caption = 'Ordonnance'
    TabOrder = 6
    Visible = False
    OnClick = Rbt_OrdonnanceClick
  end
  object Grb_update: TGroupBox
    Left = 392
    Top = 292
    Width = 410
    Height = 197
    TabOrder = 7
    object Lbl_Consigne: TLabel
      Left = 16
      Top = 16
      Width = 376
      Height = 13
      Caption = 
        'Ecrivez ce que vous voulez modifier, ne remplissez rien et rien ' +
        'ne sera modifier'
    end
    object Cmb_Medicament: TComboBox
      Left = 16
      Top = 35
      Width = 145
      Height = 21
      TabOrder = 0
      Text = 'M'#233'dicament a modifier'
    end
  end
  object Rbt_Update: TRadioButton
    Left = 543
    Top = 269
    Width = 113
    Height = 17
    Caption = 'Modifier M'#233'dicament'
    TabOrder = 8
    Visible = False
    OnClick = Rbt_UpdateClick
  end
end
