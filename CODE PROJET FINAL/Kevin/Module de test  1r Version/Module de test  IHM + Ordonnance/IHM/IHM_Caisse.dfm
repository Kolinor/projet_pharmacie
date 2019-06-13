object IHM: TIHM
  Left = 0
  Top = 0
  Caption = 'Caisse'
  ClientHeight = 194
  ClientWidth = 373
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label_Caisse: TLabel
    Left = 24
    Top = 21
    Width = 45
    Height = 13
    Caption = 'Caisse n'#176
  end
  object Bouton_Ordonnance: TButton
    Left = 96
    Top = 37
    Width = 241
    Height = 25
    Caption = 'Saisir une nouvelle ordonnance'
    TabOrder = 0
    OnClick = Bouton_OrdonnanceClick
  end
  object Bouton_EtatCommande: TButton
    Left = 96
    Top = 88
    Width = 241
    Height = 25
    Caption = 'Afficher l'#39#233'tat des commandes'
    TabOrder = 1
  end
  object Bouton_Bilan: TButton
    Left = 96
    Top = 144
    Width = 241
    Height = 25
    Caption = 'T'#233'l'#233'charger le bilan des ventes'
    TabOrder = 2
    OnClick = Bouton_BilanClick
  end
  object ComboBox_Caisse: TComboBox
    Left = 24
    Top = 40
    Width = 45
    Height = 21
    TabOrder = 3
    Items.Strings = (
      '1'
      '2'
      '3')
  end
end
